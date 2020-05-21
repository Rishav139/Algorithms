#include<bits/stdc++.h>
using namespace std;

int page_replacement=0;

int pageFaults(int pages[], int n, int frames)
{
	set<int> s;
	queue<int> indexes;

	int page_faults = 0;
	for (int i=0; i<n; i++)
	{
		if (s.size() < frames)
		{
			if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);
				page_faults++;
				cout<<"\nPage fault for page no "<<pages[i];
				indexes.push(pages[i]);
				cout<<"\n";
			}
		}
		else
		{
			if (s.find(pages[i]) == s.end())
			{
				int val = indexes.front();
				indexes.pop();
				s.erase(val);
				s.insert(pages[i]);
				indexes.push(pages[i]);
				page_faults++;
				cout<<"\nPage fault for page no "<<pages[i];
				cout<<"\nPage replacement for page no "<<pages[i];
				page_replacement++;
				cout<<"\n";
			}
		}
	}
    return page_faults;
}

int main()
{
	int req,psize,msize,val;
	cout<<"Enter memory size and page size\n";
	cin>>msize>>psize;
	cout<<"Enter no of requests\n";
	cin>>req;
    int pages[req];
    for(int i=0;i<req;i++)
    {
        cin>>val;
        pages[i]=val/psize;
    }

    cout<<"\nPage requests are \n";
    for(int i=0;i<req;i++)
        cout<<pages[i]<<" ";
    cout<<endl<<endl;

	int frames = msize/psize;
	int pf=pageFaults(pages, req, frames);
	int hits=req-pf;
	float rat=1.0*hits/req;

	cout <<"\n\nTotal page faults are "<<pf;
	cout<<"\nTotal page replacement are "<<page_replacement;
	cout<<"\nTotal hits are "<<hits;
	cout<<"\nHit Ratio "<<rat;
	return 0;
}
/*
12
10
11
104
170
73
309
185
245
246
434
458
364
*/
