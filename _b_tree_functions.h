//
//  _b_tree_functions.h
//  database
//
//  Created by Celine Seghbossian on 6/14/17.
//  Copyright (c) 2017 Celine Seghbossian. All rights reserved.
//

#ifndef database__b_tree_functions_h
#define database__b_tree_functions_h

template <typename T>
Bnode<T>* _b_insert(Bnode<T>* &rPtr, T entry)
{
    if (rPtr == NULL)
    {
        Bnode<T>* temp = new Bnode<T> (entry);
        temp->right = NULL;
        temp->left = NULL;
        rPtr = temp;
        return rPtr;
    }
    else if (entry < rPtr->data)
    {
        rPtr->left = _b_insert(rPtr->left, entry);
        rPtr = _b_balance(rPtr);
    }
    else
    {
        rPtr->right = _b_insert(rPtr->right, entry);
        rPtr = _b_balance(rPtr);
    }
    return rPtr;
}

template <typename T>
Bnode<T>* _b_balance(Bnode<T>* &rPtr)
{
    //    IF tree is right heavy
    //    {
    //        IF tree's right subtree is left heavy
    //        {
    //            Perform Double Left rotation
    //        }
    //        ELSE
    //        {
    //            Perform Single Left rotation
    //        }
    //    }
    //    ELSE IF tree is left heavy
    //    {
    //        IF tree's left subtree is right heavy
    //        {
    //            Perform Double Right rotation
    //        }
    //        ELSE
    //        {
    //            Perform Single Right rotation
    //        }
    //    }
    int bf = _bal_factor(rPtr);
    if (bf > 1) //root is left heavy
    {
        if (_bal_factor(rPtr->left) > 0)
            rPtr = _ll_rotation (rPtr);
        else
            rPtr = _lr_rotation (rPtr);
    }
    else if (bf < -1) //root is right heavy
    {
        if (_bal_factor(rPtr->right) > 0)
            rPtr = _rl_rotation (rPtr);
        else
            rPtr = _rr_rotation (rPtr);
    }
    return rPtr;
}

template <typename T>
void _b_delete(Bnode<T>* &rPtr, T entry)
{
    if (!rPtr)
        return;
    else if (entry < rPtr->data)
        _b_delete(rPtr->left, entry);
    else if (entry > rPtr->data)
        _b_delete(rPtr->right, entry);
    else if (entry == rPtr->data)
    {
        if (!rPtr->left) //no left child
        {
            Bnode<T>* temp = rPtr;
            rPtr = rPtr->right;
            delete temp;
        }
        else
            _b_remove_max(rPtr->left, rPtr->data);
    }
    _b_balance(rPtr);
}

template <typename T>
void _b_remove_max(Bnode<T>* &rPtr, T& max)
{
    if (!rPtr->right)
    {
        Bnode<T>* temp = rPtr;
        max = rPtr->data;
        rPtr = rPtr->left;
        delete temp;
    }
    else
        _b_remove_max(rPtr->right, max);
}

template <typename T>
int _depth(Bnode<T>* rPtr)
{
    if(rPtr == NULL)
        return -1;
    int l = _depth(rPtr->left);
    int r = _depth(rPtr->right);
    return (l > r) ? (l + 1) : (r + 1);
}

template <typename T>
int _bal_factor(Bnode<T>* rPtr)
{
    if (rPtr == NULL)
        return 0;
    return (_depth(rPtr->left) - _depth(rPtr->right));
}

template <typename T>
Bnode<T>* _rr_rotation(Bnode<T>* &rPtr)
{
    if(!rPtr)
        return NULL;
    Bnode<T>* temp = rPtr->right;
    rPtr->right = temp->left;
    temp->left = rPtr;
    return temp;
}

template <typename T>
Bnode<T>* _ll_rotation(Bnode<T>* &rPtr)
{
    if(!rPtr)
        return NULL;
    Bnode<T>* temp = rPtr->left;
    rPtr->left = temp->right;
    temp->right = rPtr;
    return temp;
}

template <typename T>
Bnode<T>* _lr_rotation(Bnode<T>* &rPtr)
{
    if(!rPtr)
        return NULL;
    Bnode<T>* temp = rPtr->left;
    rPtr->left = _rr_rotation (temp);
    return _ll_rotation (rPtr);
}

template <typename T>
Bnode<T>* _rl_rotation(Bnode<T>* &rPtr)
{
    if(!rPtr)
        return NULL;
    Bnode<T>* temp = rPtr->right;
    rPtr->right = _ll_rotation (temp);
    return _rr_rotation (rPtr);
}

template <typename T>
void _print(ostream& outs, Bnode<T>* rPtr, int layer = 0)
{
    if (!rPtr)
        return;
    else
    {
        _print(outs, rPtr->right, layer + 1);
        for (int i = 0; i < layer * 3; i++)
            outs<<" ";
        outs<<rPtr->data;
        outs<<endl<<endl;
        _print(outs, rPtr->left, layer + 1);
    }
}

template <typename T>
void _clear(Bnode<T>* &rPtr)
{
    Bnode<T>* temp;
    if (rPtr != NULL)
    {
        temp = rPtr->left;
        _clear(temp);
        temp = rPtr->right;
        _clear(temp);
        delete rPtr;
        rPtr = NULL;
    }
}

template <typename T>
Bnode<T>* _copy( Bnode<T>* &rPtr)
{
    Bnode<T>* l;
    Bnode<T>* r;
    
    if (rPtr == NULL)
        return NULL;
    else
    {
        l = _copy(rPtr->left);
        r = _copy(rPtr->right);
        return new Bnode<T>(rPtr->data, l, r);
    }
}

template <typename T>
Bnode<T>* _search(Bnode<T>* rPtr, T item)
{
    if (rPtr==NULL)
        return NULL;
    else if (rPtr->data == item)
        return rPtr;
    else if (item < rPtr->data)
        return _search(rPtr->left, item);
    else
        return _search(rPtr->right, item);
}

#endif
