#include <stdio.h>
#include <stdlib.h>
#define LH 1
#define EH 0
#define RH -1
#define EQ 0
#define LT -1
#define GT 1


typedef struct
{
	int _integer;
}ElemType;

typedef struct BSTNode
{
	ElemType _data;
	int _bf;
	struct BSTNode* _lchild;
	struct BSTNode* _rchild;
}BSTNode,*BSTree;

typedef enum 
{
	FAIL,
	SUCCESS
}Status;

void R_Rotate(BSTree &p)
{
	BSTree lc = p->_lchild;
	p->_lchild = lc->_rchild;
	lc->_rchild = p;
	p = lc;
}

void L_Rotate(BSTree &p)
{
	BSTree rc = p->_rchild;
	p->_rchild = rc->_lchild;
	rc->_lchild = p;
	p = rc;
}


void LeftBalance(BSTree &t)
{
	BSTree lc = t->_lchild;
	BSTree rd;
	switch (lc->_bf)
	{
	case LH:
		t->_bf = lc->_bf = EH;
		R_Rotate(t); break;
	case RH:
		rd = lc->_rchild;
		switch (rd->_bf)
		{
		case LH:
			t->_bf = RH; lc->_bf = EH; break;
		case EH:
			t->_bf = lc->_bf = EH; break;
		case RH:
			t->_bf = EH; lc->_bf = LH; break;
		}
		rd->_bf = EQ;
		L_Rotate(t->_lchild);
		R_Rotate(t);
	}
}

void RightBalance(BSTree &t)
{
	BSTree rc = t->_rchild;
	BSTree ld;
	switch (rc->_bf)
	{
	case RH:
		t->_bf = rc->_bf = EQ;
		LeftBalance(t); break;
	case LH:
		ld = rc->_lchild;
		switch (ld->_bf)
		{
		case LH:
			t->_bf = EQ; rc->_bf = RH; break;
		case EQ:
			t->_bf = rc->_bf = EH; break;
		case RH:
			t->_bf = LH; rc->_bf = EH; break;
		}
	}
	ld->_bf = EQ;
	R_Rotate(t->_rchild);
	L_Rotate(t);
}

int Compare(ElemType src,ElemType des) 
{
	if (src._integer > des._integer) 
	{
		return GT;
	}
	else if (src._integer == des._integer)
	{
		return EQ;
	}
	else 
	{
		return LT;
	}
}

Status InsertAVL(BSTree &t,ElemType e,bool &taller)
{
	if (!t)
	{
		t = (BSTree)malloc(sizeof(BSTNode));
		t->_data = e;
		t->_lchild = t->_rchild = NULL;
		taller = true;
	}
	else
	{
		if (EQ == Compare(t->_data,e))
		{
			taller = false;
			return FAIL;
		}
		else if (GT == Compare(t->_data,e))
		{
			if (!InsertAVL(t->_lchild,e,taller))
			{
				return FAIL;
			}
			if (taller)
			{
				switch (t->_bf)
				{
				case LH:
					LeftBalance(t); taller = false; break;
				case EH:
					t->_bf = LH; taller = true; break;
				case RH:
					t->_bf = EH; taller = false; break;
				}
			}
		}
		else
		{
			if (!InsertAVL(t->_rchild,e,taller))
			{
				return FAIL;
			}
			if (taller)
			{
				switch (t->_bf)
				{
				case LH:
					t->_bf = EH; taller = false; break;
				case EH:
					t->_bf = RH; taller = true; break;
				case RH:
					RightBalance(t); taller = true; break;
				}
			}
		}
	}
	return SUCCESS;
}

int main()
{
	return 0;
}