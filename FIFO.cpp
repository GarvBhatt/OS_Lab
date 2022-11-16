#include <bits/stdc++.h>

using namespace std;

//garv_bhatt

int pff(int page[],int mc,int n1)
{
    int pfff=0;
    vector<int> v;

    for(int i=0;i<n1;++i)
    {
        auto iitt=find(v.begin(),v.end(),page[i]);
        if(iitt==v.end())
        {
            if(v.size()==mc)
            {
                v.erase(v.begin());
            }
            v.push_back(page[i]);
            ++pfff;
            continue;
        }
    }
    return pfff;
}

int main()
{
    int n,mc;
    cout<<"Enter number of pages: ";
    cin>>n;
    cout<<"Enter mm capacity: ";
    cin>>mc;
    
    int page[n];

    cout<<"Ënter size of pages :  ";
    
    for(int i=0;i<n;++i)
    {
        cin>>page[i];
    }

    cout<<pff(page,mc,n);

    return 0;
}
