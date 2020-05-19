#include<bits/stdc++.h>
using namespace std;

struct Job
{
char id;	 // Job Id
int dead; // Deadline of job
int profit; // Profit if job is over before or on deadline
};

bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
	// Sort all jobs according to decreasing order of prfit
	sort(arr, arr+n, comparison);

	int result[n]; // To store result (Sequence of jobs)
	bool slot[n]; // To keep track of free time slots
    int sum=0;
	for (int i=0; i<n; i++)
		slot[i] = false;

	for (int i=0; i<n; i++)
	{
        for (int j=min(n, arr[i].dead)-1; j>=0; j--)
        {
            if (slot[j]==false)
            {
                result[j] = i; // Add this job to result
                slot[j] = true; // Make this slot occupied
                sum+=arr[i].profit;
                break;
            }
        }
	}
	for (int i=0; i<n; i++)
	if (slot[i])
		cout << arr[result[i]].id << " ";
    cout<<"\nProfit is "<<sum;
}

int main()
{
	int n;
	cout<<"Enter no of jobs\n";
	cin>>n;
	Job arr[n];
	for(int i=0;i<n;i++)
        cin>>arr[i].id>>arr[i].dead>>arr[i].profit;
	cout << "Following is maximum profit sequence of jobs ";
	printJobScheduling(arr, n);
	return 0;
}

