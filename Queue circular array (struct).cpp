 #include<iostream>
 using namespace std;
 struct Queue
 {
 	int size;
 	int f;
 	int r;
 	int element[50];
 };
 
void enq(Queue &Q, int x)
 {
 	if((Q.r+1)%Q.size==Q.f)
 	{
 		cout<<"Queue is full";
	}
	else
	{
		Q.r=(Q.r+1)%Q.size;
		Q.element[Q.r]=x;
	}
	
	if(Q.f==-1)
	{
		Q.f=0;
	}
 }
 
 int deq(Queue &Q)
 {
 	int t;
 	if(Q.f==-1)
 	{
 		cout<<"Queue is empty\n";
	}
	
	else
	{
		t=Q.element[Q.f];
		if(Q.f==Q.r)
		{
			Q.f=-1;Q.r=-1;
		}
		
		else {
			Q.f=(Q.f+1)%Q.size;
		}
	}
 }
 
 int peep(Queue &Q)
 {
 	if(Q.f==-1 ||Q.f>Q.r)
 	{
 		cout<<"Queue is empty\n";
 	}
 	
 	else
 	{
 		return Q.element[Q.f];
	}
 }
 
 void displayQueue(Queue &Q)
{
 if(Q.f==-1 || Q.f>Q.r)
  cout<<"Queue is empty\n";
 else
 {
  int i;
  if(Q.f<=Q.r )
  {
   for(i=Q.f ; i<=Q.r ; i++)
   cout<<Q.element[i]<<" ";
  }
  }
}

void showfront(Queue &Q)
{
	if(Q.f==-1 || Q.f>Q.r)
     cout<<"Queue is empty\n";
    else
    {
    	cout<<Q.element[Q.f]<<" ";
	}
	
}

 int main()
 {
 	int option, flag=1,x;
 	Queue Q;
    Q.size=50;
  	Q.f=-1;
  	Q.r=-1;
  	
  	while(flag==1)
  	{
  		cout<<"\n1.enqueue 2.dequeue 3.showfront 4.displayQueue 5.exit\n";
  	    cin>>option;
  		switch(option)
  		{
  			case 1: cout<<"Enter value\n";
  			        cin>>x;
  			        enq(Q,x);
  			        break;
  			case 2: deq(Q);
  			        break;
  		    case 3: showfront(Q);
  			        break;
  			case 4: displayQueue(Q);
  			        break;
  			case 5: flag=0;
  			        break;
  		}
  	}
}
