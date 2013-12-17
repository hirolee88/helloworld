#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 50
using namespace std;
//产生随机数
int r_number(int m,int n)
{
	int k;
	k=rand()%(n-m+1)+m;
	return k;
}
//递归法实现选择排序
void d_select(int a[N],int m,int n)
{
	int i,t,k;
	k=m;
	for(i=m+1;i<=n;i++)
		if(a[k]>a[i])
		{
			k=i;
		}
		if(k!=m)
		{
			t=a[k];
			a[k]=a[m];		
			a[m]=t;
		}
		if(m<n)
		{
			d_select(a,m+1,n);
		}
}
//递归法实现冒泡排序
void d_bubble(int *a,int n)
{
	int i;
	if(n<2)
	{
		return;
	}
	for(i=0;i<=n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	}
	d_bubble(a,n-1);
}
//非递归实现选择排序
void n_select(int a[N],int m,int n)
{
	int i,j,t,k;
	for(i=m+1;i<=n;i++)
	{
		   k=m;
		   for(j=i+1;j<=n;j++)
		   {
			  if(a[k]>a[j])
			  {
				k=j;
			  }
		   }

			if(k!=m)
			{
			  t=a[k];
			  a[k]=a[m];
			  a[m]=t;
			}
	}
}
//非递归法实现冒泡排序
void n_bubble(int *a,int n)
{
	int i,j;
	if(n<2)
	{
		return;
	}
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-i-1;j++)
		{
		  if(a[j]>a[j+1])
		  {
			int t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		  }
		}
	}
}
//快速排序算法
int q_sort_1(int a[N],int m,int n)
{
	int p,k;
	p=a[m];
	a[m]=p;
	k=m;
	while(m<n)
	{
		while(m<n&&a[n]>=p)
			--n;
		a[m]=a[n];
		while(m<n&&a[m]<=p)
			++m;
		a[n]=a[m];
	}
	a[m]=p;
	return m;
}
void q_sort_2(int a[N],int m,int n)
{
   int p;
   if(m<n)
   {
	  p=q_sort_1(a,m,n);
	  q_sort_2(a,m,p-1);
	  q_sort_2(a,p+1,n);
	}

}
void q_sort(int a[N],int n)
{
	q_sort_2(a,0,n);
}
//直接插入排序
void insert(int a[N],int n)
{
	int i,j,temp;
	for(i=0;i<=n;i++)
	{
		temp=a[i];
	//	cout<<a[i]<<endl;
		j=i-1;
		while(j>=0&&a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
	   a[j+1]=temp;
	}
}
//归并排序
void sort(int a[N],int a1[N],int s,int m,int n)
{
	int i=s;
	int j=m+1;
	int k=s;
	while(i<=m&&j<=n)
	{
		if(a[i]<=a[j])
			a1[k++]=a[i++];
		else
			a1[k++]=a[j++];
	}
	if(i<=m)
	{
		while(i<=m)
			a1[k++]=a[i++];
	}
	else while(j<=n)
	{
		a1[k++]=a[j++];
	}
	for(int l=0;l<=n;l++)
	{
		a[l]=a1[l];
	}
}

void m_sort(int a[N],int a1[N],int m,int n)
{
   int mid;
   if(m==n)
   {
	   a1[m]=a[m];
   }
   else
   {

		mid=(n+m)/2;
		m_sort(a,a1,m,mid);
		m_sort(a,a1,mid+1,n);
		sort(a1,a,m,mid,n);
   }
}
//堆排序
void h_Adjust(int a[N],int i,int length)
{
	int nChild;
	int nTemp;
	for(nTemp=a[i];2*i+1<length;i=nChild)
	{
		nChild=2*i+1;
		if(nChild<length-1&&a[nChild+1]>a[nChild])
		{
			++nChild;
		}
		if(nTemp<a[nChild])
		{
			a[i]=a[nChild];
		}
		else
			break;
		a[nChild]=nTemp;
	}
}
void h_sort(int a[N],int length)
{
	int temp;
	for(int i=length/2-1;i>=0;--i)
	{
		h_Adjust(a,i,length);
	}
	for(int j=length-1;j>0;--j)
	{
		temp=a[0];
		a[0]=a[j];
		a[j]=temp;
		h_Adjust(a,0,j);
	}
}
//希尔排序
void shell_sort(int a[N],int n)
{
	int d=n;
	while(d>1)
	{
		d=(d+1)/2;
		for(int i=0;i<n-d;i++)
		{
			if(a[i+d]<a[i])
			{
				int temp=a[i+d];
				a[i+d]=a[i];
				a[i]=temp;
			}
		}
	}
}
//计数排序
void count_sort(int*a,int n)
{
	 int temp[51]={0};
	 for(int i=0;i<=n;i++) temp[a[i]]++;
	 for( i=1;i<51;i++) temp[i]+=temp[i-1];
	 int*c=(int*)malloc(sizeof(int)*(51+1));
	 for(i=0;i<=n;i++)
	 {
			c[temp[a[i]]-1]=a[i];
			temp[a[i]]--;
	 }
	 for( i=0;i<=n;i++) a[i]=c[i];
	 free(c);
}

int main()
{
	int chooce;
	cout<<endl<<endl;
	cout<<"\t\t算法实验二"<<endl;
	cout<<"\t******************************"<<endl;
	cout<<"\t1.递归实现选择排序"<<endl;
	cout<<"\t2.递归实现冒泡排序"<<endl;
	cout<<"\t3.非递归实现选择排序"<<endl;
	cout<<"\t4.非递归实现冒泡排序"<<endl;
	cout<<"\t5.快速排序算法"<<endl;
	cout<<"\t6.直接插入排序"<<endl;
	cout<<"\t7.归并排序"<<endl;
	cout<<"\t8.堆排序"<<endl;
	cout<<"\t9.希尔排序"<<endl;
	cout<<"\t10.计数排序"<<endl;
	cout<<"\t11.退出"<<endl;
	cout<<"\t******************************"<<endl;
	cout<<"\t\tmade by zhangmei 2012-5-24"<<endl;
	cout<<"请输入您的选择:"<<endl;
	cin>>chooce;
	switch(chooce)
	{
	   int i;
	case 1:
		{
			//递归实现选择排序
			int n;
			int a[N];
			cout<<"请输入您需要排序的个数N:"<<endl;
			cin>>n;
			cout<<"产生的随机数为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				a[i]=r_number(40,50);
				cout<<a[i]<<"\t";
			}
			cout<<endl;
			d_select(a,0,n-1);
			cout<<"排序后的结果为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				cout<<a[i]<<"\t";
			}
		}
		break;
	case 2:
		{
			//递归实现选择排序
			int n;
			int a[N];
			cout<<"请输入您需要排序的个数N:"<<endl;
			cin>>n;
			cout<<"产生的随机数为:"<<endl;
			for( i=0;i<=n-1;i++)
			{
				a[i]=r_number(40,50);
				cout<<a[i]<<"\t";
			}
			cout<<endl;
			d_bubble(a,n-1);
			cout<<"排序后的结果为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				cout<<a[i]<<"\t";
			}
		}
		break;
	case 3:
		{
			int n;
			int a[N];
			cout<<"请输入您需要排序的个数N:"<<endl;
			cin>>n;
			cout<<"产生的随机数为:"<<endl;
			for( i=0;i<=n-1;i++)
			{
				a[i]=r_number(40,50);
				cout<<a[i]<<"\t";
			}
			cout<<endl;
			n_select(a,0,n-1);
			cout<<"排序后的结果为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				cout<<a[i]<<"\t";
			}
		}
		break;
	case 4:{
			int n;
			int a[N];
			cout<<"请输入您需要排序的个数N:"<<endl;
			cin>>n;
			cout<<"产生的随机数为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				a[i]=r_number(40,50);
				cout<<a[i]<<"\t";
			}
			cout<<endl;
			n_bubble(a,n-1);
			cout<<"排序后的结果为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				cout<<a[i]<<"\t";
			}
		   }
		break;
	case 5:
		{
			int n;
			int a[N];
			cout<<"请输入您需要排序的个数N:"<<endl;
			cin>>n;
			cout<<"产生的随机数为:"<<endl;
			for( i=0;i<=n-1;i++)
			{
				a[i]=r_number(40,50);
				cout<<a[i]<<"\t";
			}
			cout<<endl;
			 q_sort(a,n-1);
			cout<<"排序后的结果为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				cout<<a[i]<<"\t";
			}

		}
		break;
	case 6:
		{
			int n;
			int a[N];
			cout<<"请输入您需要排序的个数N:"<<endl;
			cin>>n;
			cout<<"产生的随机数为:"<<endl;
			for( i=0;i<=n-1;i++)
			{
				a[i]=r_number(40,50);
				cout<<a[i]<<"\t";
			}
			cout<<endl;
			 insert(a,n-1);
			cout<<"排序后的结果为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				cout<<a[i]<<"\t";
			}
		}
		break;
	case 7:
		{
			int n;
			int a[N],a1[N];
			cout<<"请输入您需要排序的个数N:"<<endl;
			cin>>n;
			cout<<"产生的随机数为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				a[i]=r_number(40,50);
				cout<<a[i]<<"\t";
			}
			cout<<endl;
			m_sort(a,a1,0,n-1);
			cout<<"排序后的结果为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				cout<<a[i]<<"\t";
			}

		}
		break;
	case 8:{
			int n;
			int a[N];
			cout<<"请输入您需要排序的个数N:"<<endl;
			cin>>n;
			cout<<"产生的随机数为:"<<endl;
			for( i=0;i<=n-1;i++)
			{
				a[i]=r_number(40,50);
				cout<<a[i]<<"\t";
			}
			cout<<endl;
			 h_sort(a,n);
			cout<<"排序后的结果为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				cout<<a[i]<<"\t";
			}
		   }
		break;
	case 9:{
			int n;
			int a[N];
			cout<<"请输入您需要排序的个数N:"<<endl;
			cin>>n;
			cout<<"产生的随机数为:"<<endl;
			for( i=0;i<=n-1;i++)
			{
				a[i]=r_number(40,50);
				cout<<a[i]<<"\t";
			}
			cout<<endl;
			shell_sort(a,n);
			cout<<"排序后的结果为:"<<endl;
			for(i=0;i<=n-1;i++)
			{
				cout<<a[i]<<"\t";
			}
		   }break;
	case 10:
		{
			int n;
			int a[N];
			cout<<"请输入您需要排序的个数N:"<<endl;
			cin>>n;
			cout<<"产生的随机数为:"<<endl;
			for( i=0;i<=n-1;i++)
			{
				a[i]=r_number(40,50);
				cout<<a[i]<<"\t";
			}
			cout<<endl;
			count_sort(a,n-1);
			cout<<"排序后的结果为:"<<endl;
			for(i=0;i<n;i++)
			{
				cout<<a[i]<<"\t";
			}

		}
		break;
	case 11:exit(0);
	}

	system("pause");
	return 0;
}