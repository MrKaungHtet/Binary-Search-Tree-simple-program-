#include<iostream>
#include<iomanip>
using namespace std;

struct Node
{
    int value;
    Node * left=NULL;
    Node * right=NULL;
};

class Tree
{
    private:
        int node=0;
        Node * Root=NULL;
        Node * Current;
        Node * Current1;
        Node * Temp;
        Node * Temp1;
        
    public:
        void Add(int&);
        void Display();
        void Remove(int&);
        bool Search(int&);
        int Min();
        int Max();
        int getHeight();
        int getRoot();
        int getNode();
        void poll();
            
};


//adding a data to the tree...
void Tree::Add(int& x)
{
    if (Root==NULL)
    {
        node++;
        Root=new Node;
        (*Root).value=x;
    }
    else
    {
        Current=Root;
        while(Current!=NULL and (*Current).value!=x)
        {
            Temp=Current;
            if(x<(*Current).value)
            {
                Current=(*Current).left;
            }
            else
            {
                Current=(*Current).right;
            }
        }
        if (Current==NULL)
        {
            node++;
            Current= new Node;
            (*Current).value=x;
            
            if(x<(*Temp).value)
            {
                (*Temp).left=Current;
            }
            else
            {
                (*Temp).right=Current;
            }
        }
    }
}

void inorder(Node * n)
{
    if(n!=NULL)
    {
        inorder((*n).left);
        cout<<right<<setw(5)<<(*n).value;
        inorder((*n).right);
    }
}

void preorder(Node * n)
{
    if(n!=NULL)
    {
        preorder((*n).left);
        preorder((*n).right);
        cout<<right<<setw(5)<<(*n).value;
    }
}

void postorder(Node * n)
{
    if(n!=NULL)
    {
        cout<<right<<setw(5)<<(*n).value;
        postorder((*n).left);
        postorder((*n).right);
    }
}

//inorder (left,root,right)
//preorder(left,right,root)
//postorder(root,left,right)
void Tree::Display()
{
    cout<<left<<setw(13)<<"In Order: ";
    inorder(Root);
    cout<<endl;
    cout<<left<<setw(13)<<"Pre Order: ";
    preorder(Root);
    cout<<endl;
    cout<<left<<setw(13)<<"Post Order: ";
    postorder(Root);
}

int H(Node * n)
{
    if(n==NULL)
    {
        return 0;
    }
    else
    {
        if(H((*n).left)<H((*n).right))
        {
            return 1+H((*n).right);
        }
        else
        {
            return 1+H((*n).left);
        }
    }
}



void Tree::Remove(int& x)
{
    if(x!=(*Root).value)
    {
        Current = Root;
        while (Current!=NULL and 
                  (*Current).value!=x)
        {
            Temp=Current;
            if(x<(*Current).value)
            {
                Current=(*Current).left;
            }
            else
            {
                Current=(*Current).right;
            }
        }
        
        if(Current!=NULL)
        {
            if((*Current).left==NULL and (*Current).right==NULL)
            {
                if(x<(*Temp).value)
                {
                    (*Temp).left=NULL;
                }
                else
                {
                    (*Temp).right=NULL;
                }
                delete Current;
                node--;
            }
            if((*Current).left!=NULL and (*Current).right==NULL)
            {
                Current1=(*Current).left;
                if((*Current1).right==NULL)
                {
                    (*Current).value=(*Current1).value;
                    (*Current).left=(*Current1).left;
                    
                    delete Current1;
                    node--;
                }
                else
                {
                    while((*Current1).right!=NULL)
                    {
                        Temp=Current1;
                        Current1=(*Current1).right;
                    }
                    (*Current).value=(*Current1).value;
                    (*Temp).right=(*Current1).left;
                    delete Current1;
                    node--;
                }
            }
            
            if((*Current).left==NULL and (*Current).right!=NULL)
            {
                Current1=(*Current).right;
                if((*Current1).left==NULL)
                {
                    (*Current).value=(*Current1).value;
                    (*Current).right=(*Current1).right;
                    delete Current1;
                    node--;
                }
                else
                {
                    while((*Current1).left!=NULL)
                    {
                        Temp=Current1;
                        Current1=(*Current1).left;
                    }
                    (*Current).value=(*Current1).value;
                    (*Temp).left=(*Current1).right;
                    delete Current1;
                    node--;
                }
            }
            
            if((*Current).left!=NULL and (*Current).right!=NULL)
            {
                if(H((*Current).left)<H((*Current).right))
                {
                    Current1=(*Current).right;
                    if((*Current1).left==NULL)
                    {
                        (*Current).value=(*Current1).value;
                        (*Current).right=(*Current1).right;
                        delete Current1;
                        node--;
                    }
                    else
                    {
                        while((*Current1).left!=NULL)
                        {
                            Temp=Current1;
                            Current1=(*Current1).left;
                        }
                        (*Current).value=(*Current1).value;
                        (*Temp).left=(*Current1).right;
                        delete Current1;
                        node--;
                    }
                }
                else
                {
                    Current1=(*Current).left;
                    if((*Current1).right==NULL)
                    {
                        (*Current).value=(*Current1).value;
                        (*Current).left=(*Current1).left;
                        
                        delete Current1;
                        node--;
                    }
                    else
                    {
                        while((*Current1).right!=NULL)
                        {
                            Temp=Current1;
                            Current1=(*Current1).right;
                        }
                        (*Current).value=(*Current1).value;
                        (*Temp).right=(*Current1).left;
                        delete Current1;
                        node--;
                    }
                }
            }
        }
    }
}

int Tree::Min()
{
    if(Root==NULL)
    {
        return 0;
    }
    else
    {
        Current=Root;
        while((*Current).left!=NULL)
        {
            Current=(*Current).left;
        }
        return (*Current).value;
    }
}

int Tree::getHeight()
{
    return H(Root);
}

int Tree::getRoot()
{
    if(Root!=NULL)
    {
        return (*Root).value;
    }
    
    else
    {
        return NULL;
    }
}

int Tree::getNode()
{
    return node;
}

int Tree::Max()
{
    if(Root==NULL)
    {
        return 0;
    }
    else
    {
        Current=Root;
        while((*Current).right!=NULL)
        {
            Current=(*Current).right;
        }
        return (*Current).value;
    }
}

bool Tree::Search(int& x)
{
    Current=Root;
    while(Current!=NULL and (*Current).value!=x)
    {
        if(x<(*Current).value)
        {
            Current=(*Current).left;
        }
        else
        {
            Current=(*Current).right;
        }
    }
    return Current!=NULL;
}

void Tree::poll()
{
    if(Root!=NULL)
    {
        if((*Root).left==NULL and (*Root).right==NULL)
        {
            Root=NULL;
            delete Root;
            node--;
        }
        
        else if(((*Root).left!=NULL and (*Root).right==NULL) or H((*Root).right)<=H((*Root).left))
        {
            Current=(*Root).left;
            if((*Current).right==NULL)
            {
                (*Root).value=(*Current).value;
                (*Root).left=(*Current).left;
                delete Current;
                node--;
            }
            
            else
            {
                while((*Current).right!=NULL)
                {
                    Temp=Current;
                    Current=(*Current).right;
                }
                (*Root).value=(*Current).value;
                (*Temp).right=(*Current).left;
                delete Current;
                node--;
            }
        }
        
        else if(((*Root).left==NULL and (*Root).right!=NULL) or H((*Root).right)>H((*Root).left))
        {
            Current=(*Root).right;
            if((*Current).left==NULL)
            {
                (*Root).value=(*Current).value;
                (*Root).right=(*Current).right;
                delete Current;
                node--;
            }
            
            else
            {
                while((*Current).left!=NULL)
                {
                    Temp=Current;
                    Current=(*Current).left;
                }
                (*Root).value=(*Current).value;
                (*Temp).left=(*Current).right;
                delete Current;
                node--;
            }
        }
        
    }
}


int main()
{
	Tree t;
	int value;
	string cmd;
	
	cout<<"     "<<left<<setw(13)<<"add "<<"- to add a num to the tree.";
	cout<<endl;
	cout<<"     "<<left<<setw(13)<<"remove "<<"- to remove the num from the tree.";
	cout<<endl;
	cout<<"     "<<left<<setw(13)<<"poll"<<"- to remove the root from the tree.";
	cout<<endl;
	cout<<"     "<<left<<setw(13)<<"depth"<<"-will display the depth of the tree.";
	cout<<endl;
	cout<<"     "<<left<<setw(13)<<"max"<<"-will display the maximun num.";
	cout<<endl;
	cout<<"     "<<left<<setw(13)<<"min"<<"-will display the minimun num.";
	cout<<endl;
	cout<<"     "<<left<<setw(13)<<"root"<<"-will display the root of the tree.";
	cout<<endl;
	cout<<"     "<<left<<setw(13)<<"search"<<"-will tell you, that the num you search exist or not.";
	cout<<endl;
	cout<<"     "<<left<<setw(13)<<"display"<<"-will display the tree in inorder,preorder,postorder forms.";
	cout<<endl;
	
	
	
	start:
	
	cout<<"cmd>";
	cin>>cmd;
	
	if (cmd=="add")
	{
	    cin>>value;
	    t.Add(value);
	}
	
	if (cmd=="display")
	{
	    cout<<endl;
	    t.Display();
	    cout<<endl;
	    cout<<endl;
	}
	
	if (cmd=="remove")
	{
	    cin>>value;
	    t.Remove(value);
	}
	
	if (cmd=="search")
	{
	    cin>>value;
	    if(t.Search(value))
	    {
	        cout<<value<<" is Exist";
	    }
	    else
	    {
	        cout<<value<<" do not Exist";
	    }
	    cout<<endl;
	}
	
	if (cmd=="max")
	{
	    cout<<t.Max();
	    cout<<endl;
	}
	
	if (cmd=="min")
	{
	    cout<<t.Min();
	    cout<<endl;
	}
	
	if (cmd=="depth")
	{
	    cout<<t.getHeight();
	    cout<<endl;
	}
	
	if (cmd=="root")
	{
	    cout<<t.getRoot();
	    cout<<endl;
	}
	if (cmd=="node")
	{
	    cout<<t.getNode();
	    cout<<endl;
	}
	if (cmd=="poll")
	{
	    t.poll();
	}
	
	goto start;
	
}
