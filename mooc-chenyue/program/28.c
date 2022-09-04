#include <stdio.h>
#include <stdlib.h>
struct person
{
	int user_id;
	int total_score;
	int perfect_solved;
	int rank;
	int *partial_score;
};
typedef struct person *Person;
typedef struct person ElementType;
void Delete_wrap(void);
void Swap(ElementType *A1,ElementType *A2);
void BubbleSort_total_score(ElementType A[],int N);
void BubbleSort_perfect_solved(ElementType A[],int N);
void BubbleSort_user_id(ElementType A[],int N);
void PrintResult(ElementType A[],int N,int problem_count);
int main(void)
{
	int tmp_user_id,tmp_problem_id,tmp_partial_score,tmp_count;
	int index,i;
	int user_count,problem_count,submission_count;
	scanf("%d %d %d\n",&user_count,&problem_count,&submission_count);
	int perfect_scores[problem_count];
	for(index=0;index<problem_count;index++)
		scanf("%d",&perfect_scores[index]);
	Delete_wrap();
	//初始化数组
	Person students=malloc(sizeof(struct person)*user_count);
	for(index=0;index<user_count;index++)
	{
		students[index].user_id=index+1;
		students[index].total_score=0;
		students[index].perfect_solved=0;
		students[index].partial_score=malloc(sizeof(int)*problem_count);
		for(i=0;i<problem_count;i++)
			students[index].partial_score[i]=-1;
	}
	//读入数据
	for(i=0;i<submission_count;i++)
	{
		scanf("%d %d %d",&tmp_user_id,&tmp_problem_id,&tmp_partial_score);
		Delete_wrap();
		if(tmp_partial_score>-1)
		{
			if(tmp_partial_score==perfect_scores[tmp_problem_id-1]&&students[tmp_user_id-1].partial_score[tmp_problem_id-1]!=perfect_scores[tmp_problem_id-1])
				students[tmp_user_id-1].perfect_solved+=1;
			if(tmp_partial_score>students[tmp_user_id-1].partial_score[tmp_problem_id-1])
			{
				if(students[tmp_user_id-1].partial_score[tmp_problem_id-1]>0)
				{
					students[tmp_user_id-1].total_score-=students[tmp_user_id-1].partial_score[tmp_problem_id-1];
					students[tmp_user_id-1].total_score+=tmp_partial_score;
					students[tmp_user_id-1].partial_score[tmp_problem_id-1]=tmp_partial_score;
				}
				else
				{
					students[tmp_user_id-1].total_score+=tmp_partial_score;
					students[tmp_user_id-1].partial_score[tmp_problem_id-1]=tmp_partial_score;
				}
			}
		}
	}
	//去除总分等于零的数据
	tmp_count=user_count;
	for(i=0;i<user_count;i++)
	{
		if(students[i].total_score<=0)
		{
			if(i<user_count-1)
			{
				for(index=i;index<user_count-1;index++)
					students[index]=students[index+1];
				tmp_count--;
			}
			else
				tmp_count--;
		}
	}
	user_count=tmp_count;
	//依据总分排序，并且为rank赋值
	BubbleSort_total_score(students,user_count);
	//依据得满分的题数排序
	BubbleSort_perfect_solved(students,user_count);
	//依据用户编号排序
	BubbleSort_user_id(students,user_count);
	PrintResult(students,user_count,problem_count);
	return 0;
}
void Delete_wrap(void)
{
	char ch;
	while((ch=getchar())!='\n')
		;
}
void Swap(ElementType *A1,ElementType *A2)
{
        ElementType Tmp;
        Tmp=*A1;
        *A1=*A2;
        *A2=Tmp;
}





void BubbleSort_total_score(ElementType A[],int N)
{
	int P,flag,i,count;
	for(P=N-1;P>=0;P--)
	{
		flag=0;
		for(i=0;i<P;i++)
		{
			if(A[i].total_score<A[i+1].total_score)
			{
				Swap(&A[i],&A[i+1]);
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	for(i=0,P=0,flag=-1,count=0;i<N;i++)
	{
		if(A[i].total_score==flag)
		{
			A[i].rank=P;
			count++;
		}
		else
		{
			flag=A[i].total_score;
			P+=count+1;
			count=0;
			A[i].rank=P;
		}
	}
}
void BubbleSort_perfect_solved(ElementType A[],int N)
{
	int index;
	int first,last;
	int flag,i,P;
	for(index=0,first=-1,last=-1;index<N-1;index++)
	{
		if(A[index].rank==A[index+1].rank&&first==-1)
			first=index;
		if(A[index].rank!=A[index+1].rank&&first!=-1)
		{
			last=index;
			for(P=last;P>=first;P--)
			{
				flag=0;
				for(i=first;i<P;i++)
				{
					if(A[i].perfect_solved<A[i+1].perfect_solved)
					{
						Swap(&A[i],&A[i+1]);
						flag=1;
					}
				}
				if(flag==0)
				{
					first=-1;
					last=-1;
					break;
				}
			}
		}
	}
}
void BubbleSort_user_id(ElementType A[],int N)
{
	int index;
	int first,last;
	int flag,i,P;
	for(index=0,first=-1,last=-1;index<N-1;index++)
	{
		if(A[index].rank==A[index+1].rank&&A[index].perfect_solved==A[index+1].perfect_solved&&first==-1)
			first=index;
		if((A[index].rank!=A[index+1].rank||A[index].perfect_solved!=A[index+1].perfect_solved)&&first!=-1)
		{
			last=index;
			for(P=last;P>=first;P--)
			{
				flag=0;
				for(i=first;i<P;i++)
				{
					if(A[i].user_id>A[i+1].user_id)
					{
						Swap(&A[i],&A[i+1]);
						flag=1;
					}
				}
				if(flag==0)
				{
					first=-1;
					last=-1;
					break;
				}
			}
		}
	}
}
void PrintResult(ElementType A[],int N,int problem_count)
{
	int index,i;
	for(index=0;index<N;index++)
	{
		printf("%d %05d %d ",A[index].rank,A[index].user_id,A[index].total_score);
		for(i=0;i<problem_count;i++)
		{
			if(A[index].partial_score[i]!=-1)
				printf("%d",A[index].partial_score[i]);
			else
				printf("-");
			if(i<problem_count-1)
				printf(" ");
		}
		if(index<N-1)
			printf("\n");
	}
}
