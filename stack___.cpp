#include<iostream>

using namespace std;

//garv_bhatt

class Stack_
{
    private:
    int n,top,*arr=new int[n];
    
    public:
    Stack_(int n)
    {
        top=-1;
        this->n=n;
        for(int i=0;i<n;i++)
        {
            arr[i]=0;
        }
    }

    void display_my_stack(void)
    {
        for(int i=(n-1);i>=0;i--)
        {
            cout<<"\t"<<arr[i]<<"\n";
        }
    }

    bool is_it_empty(void)
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool is_it_full(void)
    {
        if(top==n-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int tape)
    {
        if(is_it_full())
        {
            cout<<"\tStack is full";
            return;
        }
        else
        {
            top++;
            arr[top]=tape;
        }
    }

    int pop(void)
    {
        if(is_it_empty())
        {
            cout<<"\tStack is empty:";
            return 0;
        }
        else
        {
            int tape=arr[top];
            arr[top]=0;
            top--;

            return tape;
        }
    }

    int count_eleme(void)
    {
        return top+1;
    }

    void change_(int index,int tape)
    {
        arr[index-1]=tape;
    }

    int peek(int index)
    {
        if(is_it_empty())
        {
            cout<<"\tStack is empty:";
            return 0;
        }
        else
        {
            return arr[index-1];
        }
    }

    void destroy_stack(void)
    {
        delete[] arr;
    }
};

int main()
{
    int n;

    cout<<"\tPlease enter the size of stack : ";
    cin>>n;

    Stack_ s2(n);

    do
    {
        int temp,socity,x;
        cout<<"\n\n\tWhatever you want chosse from bellow options \n\tor just enter 0 to destroy the stack  \n\n\t1.)pop \n\n\t2.)push \n\n\t3.)display my stack.. \n\n\t4.)change.. \n\n\t5.)count.. \n\n\t6.)if_it_empty.. \n\n\t7.)is_it_full..\n\n\t8.)clear screen..\n\n\t9.)peek..\n\n\n\tEnter your choice here : ";
        cin>>socity;

        switch (socity)
        {
            case 0:
            exit(0);
            s2.destroy_stack();
            break;

            case 1:
            if(!s2.is_it_empty())
            {
                cout<<"\tempty"<<s2.pop();
            }
            else
            {
                s2.pop();
            }
            break;

            case 2:
            cout<<"Enter the number you want to push inside : ";
            cin>>temp;
            s2.push(temp);
            break;

            case 3:
            cout<<"Here's your stack  : \n\n";
            s2.display_my_stack();
            break;

            case 4:
            cout<<"\tenter position : ";
            cin>>x;
            cout<<"\t  number : ";
            cin>>temp;
            s2.change_(x,temp);
            break;

            case 5:
            cout<<"\tThere are  "<<s2.count_eleme()<<" elements";
            break;

            case 6:
            if(s2.is_it_empty())
            {
                cout<<"\tStack is empty: ";
            }
            else
            {
                cout<<"\tno its not";
            }
            break;

            case 7:
            if(s2.is_it_full())
            {
                cout<<"\tStack is full";
            }
            else
            {
                cout<<"\tno its not";
            }
            break;

            case 8:
            system("cls");
            break;
            
            case 9:
            cout<<"\n\tenter position of element: ";
            cin>>x;
            if(!s2.is_it_empty())
            {
                cout<<"\there's your element "<<s2.peek(x);
            }
            else
            {
                s2.peek(x);
            }
            break;

            default:
            cout<<"\tinvalid choice";
            break;
        }
    }while(true);

    return 0;
}