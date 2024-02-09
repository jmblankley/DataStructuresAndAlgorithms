#include "AVLTree.hpp"

using namespace std;

AVLTreeNode* findHelper(AVLTreeNode *inSubTree, int valToFind)
{
    if (!inSubTree)
        return nullptr;

    if (inSubTree->data() == valToFind)
        return inSubTree;

    if (inSubTree->data() < valToFind)
        return findHelper(inSubTree->right(), valToFind);

    // must be in left subtree (or we would already have returned)
    return findHelper(inSubTree->left(), valToFind);
}

AVLTreeNode*
AVLTree:: find(int valToFind) const
{
    return findHelper(_root, valToFind);
}

//ADDDED CODE HERE
int getHeight(const AVLTreeNode *subTree)
{
  if (!subTree)
    return 0;
  else
    return subTree->height();
}

// a single rotation , pulling up left child
//  k2 - the current root. 
//  returns the new root. 
AVLTreeNode* rotateRight(AVLTreeNode *k2)
{
  AVLTreeNode *subtreeParent = k2->parent();
  // NOTE: See course notes for picture of what k1 and k2 (and Y) mean here
  AVLTreeNode *k1 = k2->left();
  k2->left() = k1->right(); // Y
  k1->right() =  k2;

  // we just moved things around. Update associated subtree heights. 
  k2->height() = 1 + max (getHeight(k2->left()), getHeight(k2->right()) );
  k1->height() = 1 + max (getHeight(k1->left()), getHeight(k2) );

  // fix parent ptrs.
  k2->parent() = k1;
  if (k2->left()) k2->left()->parent()=k2; // patch Y's parent
  k1->parent() = subtreeParent;

  return k1;
}

// a single rotation , pulling up right child
//  k2 - the current root. 
//  returns the new root. 
AVLTreeNode* rotateLeft(AVLTreeNode *k2)
{
  AVLTreeNode *subtreeParent = k2->parent();

  // NOTE: See course notes for picture of what k1 and k2 (and Y) mean here
  AVLTreeNode *k1 = k2->right();
  k2->right() = k1->left(); // Y
  k1->left() =  k2;

  // we just moved things around. Update associated subtree heights. 
  k2->height() = 1 + max (getHeight(k2->left()), getHeight(k2->right()) );
  k1->height() = 1 + max (getHeight(k1->right()), getHeight(k2) );

  // fix parent ptrs.
  k2->parent() = k1;
  if (k2->right()) k2->right()->parent()=k2; // patch Y's parent
  k1->parent() = subtreeParent;

  return k1;
}

AVLTreeNode* doubleWithLeftChild(AVLTreeNode *k3)
{
  AVLTreeNode *k1 = k3->left();
  k3->left() = rotateLeft(k1);
  return rotateRight(k3);
}

AVLTreeNode* doubleWithRightChild(AVLTreeNode *k3)
{
  AVLTreeNode *k1 = k3->right();
  k3->right() = rotateRight(k1);
  return rotateLeft(k3);
}



// intoSubTree -- the subtree into which we want to insert
// returns : updated version of subtree
AVLTreeNode* insertHelper(AVLTreeNode *intoSubTree, int valToAdd)
{
    if (intoSubTree == nullptr) // empty tree!
    {
        AVLTreeNode *newTree = new AVLTreeNode(valToAdd);
        return newTree;
    }
    if (valToAdd < intoSubTree->data() )
    {
        // want to insert in left subtree
        AVLTreeNode *newSubTree = insertHelper(intoSubTree->left(), valToAdd);
        intoSubTree->left() = newSubTree;
        newSubTree->parent() = intoSubTree;

        // might need AVL rotations ... look at children's heights to decide
        int leftHeight = getHeight(intoSubTree->left());
        int rightHeight = getHeight(intoSubTree->right());

        // left imbalance
        if (leftHeight-rightHeight==2) 
	{
	  // is this a left-left imbalance?
	  if (valToAdd < intoSubTree->left()->data() )
	  {
	      intoSubTree=rotateRight(intoSubTree);
	  }
	  // or is it a left-rght imabalance?
	  else
	  {
	      intoSubTree=doubleWithLeftChild(intoSubTree);
	  }
	}
    }
    else if (valToAdd > intoSubTree->data() )
    {
        // want to insert into right subtree
        AVLTreeNode *newSubTree = insertHelper(intoSubTree->right(), valToAdd);
        intoSubTree->right() = newSubTree;
        newSubTree->parent() = intoSubTree;

        // might need AVL rotations ... look at children's heights to decide
        int leftHeight = getHeight(intoSubTree->left());
        int rightHeight = getHeight(intoSubTree->right());

        // check for right imbalance
        if (rightHeight-leftHeight==2) 
	{
	  // is this a right-right imbalance?
	  if (valToAdd >  intoSubTree->right()->data() )
	    {
	      intoSubTree=rotateLeft(intoSubTree);
	    }
	  // or is it a right-left imabalance?
	  else
	    {
	      intoSubTree=doubleWithRightChild(intoSubTree);
	    }
	}
    }
    else // == ... so already found in subtree!!
    {
      
    }

    // now that we've mved things areound, need to update this nodes height. 
    intoSubTree->height() = 1 + max(getHeight(intoSubTree->left()),
				    getHeight(intoSubTree->right()) ); 
    return intoSubTree;
}



void
AVLTree::insert(int newVal)
{
    _root=insertHelper(_root, newVal);
}




void
AVLTree::remove(int existingVal)
{
    AVLTreeNode *toDel = find(existingVal);
    if (!toDel)
    {
        cerr << "Sorry, \"" << existingVal << "\" is not in tree!"
            << endl;
        return;
    }
    // case 1: no children ...
    if (toDel->isLeaf())
    {
        // special case
        if (toDel == _root)
        {
            _root=nullptr;
            return;
        }
        AVLTreeNode *parent = toDel->parent();

        if (parent->left() == toDel)
            parent->left() = nullptr;
        else // must be on the right
            parent ->right() = nullptr;

        // following is not strictly necessary ...
        //    .. but lets "clean up" toDel
        toDel->parent() = nullptr;
        delete toDel;  // depending on application, don't do this
        return;
    }
    // case 2: one children
    else if ( ( toDel->right() && !toDel->left() ) ||
              ( toDel->left() && !toDel->right() )
            )
    {
        if (toDel==_root)
        {
            if (toDel->left())
                _root=toDel->left();
            else
                _root=toDel->right();

            _root->parent() = nullptr;
            return;
        }

        AVLTreeNode *subTree;
        if (toDel->left())
            subTree=toDel->left();
        else
            subTree=toDel->right();

        AVLTreeNode *parent = toDel->parent();
        if (parent->left() == toDel)
            parent->left() = subTree;
        else
            parent->right() = subTree;

        subTree->parent() = parent;

        // following is not strictly necessary ...
        //    .. but lets "clean up" toDel
        toDel->left() = toDel->right() = nullptr;
        toDel->parent() = nullptr;
        delete toDel;  // depending on application, don't do this
    }
    // case 3: two children
    else
    {
        // hop once to the right
        AVLTreeNode *curr = toDel->right();
        // go as far left as you can ...
        while (curr->left() )
            curr=curr->left();

        int valToSave = curr->data();
        remove(valToSave);
        toDel->data() = valToSave;
        return;
    }

}


void inOrderPrint(AVLTreeNode *currNode, ostream &os)
{
    if (currNode==nullptr)
        return;

    inOrderPrint(currNode->right(), os);

    // indent the node properly to display as tree
    for (int indentCount=0; indentCount<currNode->depth(); indentCount++)
        os << "    ";
    currNode->print(os);
    os << "( " << getHeight(currNode->left()) 
       << "   <==>   "
       << getHeight(currNode->right()) << " )";
    os << endl;

    inOrderPrint(currNode->left(), os);
}

std::ostream&
AVLTree::print(std::ostream &someStream) const
{
    inOrderPrint(_root, someStream);
    return someStream;
}







