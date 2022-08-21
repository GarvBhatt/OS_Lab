#include<iostream>

using namespace std;

//garv_bhatt

class queue
{
    private:
    int n, front, last, *arr;

    public:
    queue(int n)
    {
        front=-1;
        last=-1;
        this->n=n;
        arr=new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=0;
        }
    }

    void display_the_queue(void)
    {
        for(int i=0;i<n;i++)
        {
            cout<<"\t"<<arr[i];
        }
    }

    bool is_it_empty(void)
    {
        if(front==-1 && last==-1)
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
        if(last==n-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int tape)
    {
        if(is_it_full())
        {
            cout<<"\tqueue is full";
            return;
        }
        else if (is_it_empty())
        {
            front=0;
            last=0;
            arr[last]=tape;
        }
        else
        {
            last++;
            arr[last]=tape;
        }
    }

    int dequeue(void)
    {
        if(is_it_empty())
        {
            cout<<"\tqueue is empty";
            return 0;
        }
        else if(front==last)
        {
            int tape=arr[front];
            arr[front]=0;
            front=-1;
            last=-1;
            
            return tape;
        }
        else
        {
            int tape=arr[front];
            arr[front]=0;
            front++;

            return tape;
        }
    }

    int count__(void)
    {
        return last+1-front;
    }

    void change__(int index,int tape)
    {
        arr[index-1]=tape;
    }

    int peek__(int index)
    {
        if(is_it_empty())
        {
            cout<<"\tqueue is empty";
            return 0;
        }
        else
        {
            return arr[index-1];
        }
    }

    void destroyer(void)
    {
        delete[] arr;
    }
};

int main()
{
    int n;

    cout<<"\tPlease enter the size of queue you want to create : ";
    cin>>n;

    queue itsAqueue(n);

    do
    {
        int socity, temp, G;
        cout<<"\n\n\tWhatever you want to do chosse from bellow options \n\tor just enter 0 to destroy the queue\n\n\t1.)pop \n\n\t2.)push \n\n\t3.)queue \n\n\t4.)change \n\n\t5.)count \n\n\t6.)is it empty \n\n\t7.)is it full \n\n\t8.)clear screen \n\n\t9.)peek\n\n\n\tEnter your choice here : ";
        cin>>socity;

        switch (socity)
        {
            case 0:
            exit(0);
            itsAqueue.destroyer();
            break;

            case 1:
            if(!itsAqueue.is_it_empty())
            {
                cout<<"\tyou poped "<<itsAqueue.dequeue();
            }
            else
            {
                itsAqueue.dequeue();
            }
            break;

            case 2:
            cout<<"Enter the number you want to push inside : ";
            cin>>temp;
            itsAqueue.enqueue(temp);
            break;

            case 3:
            cout<<"Here's your queue : \n\n";
            itsAqueue.display_the_queue();
            break;

            case 4:
            cout<<"\tenter position : ";
            cin>>temp;
            cout<<"\tnumber : ";
            cin>>G;
            itsAqueue.change__(temp,G);
            break;

            case 5:
            cout<<"\tYou got "<<itsAqueue.count__()<<"elements";
            break;

            case 6:
            if(itsAqueue.is_it_empty())
            {
                cout<<"\tqueue is empty";
            }
            else
            {
                cout<<"\tno its not";
            }
            break;

            case 7:
            if(itsAqueue.is_it_full())
            {
                cout<<"\tqueue is full";
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
            cout<<"\n\tenter position: ";
            cin>>temp;
            if(!itsAqueue.is_it_empty())
            {
                cout<<"\there's your element "<<itsAqueue.peek__(temp);
            }
            else
            {
                itsAqueue.peek__(temp);
            }
            break;

            default:
            cout<<"\tinvalid choice";
            break;
        }
    }while(true);

    return 0;
}