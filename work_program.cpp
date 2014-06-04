#include<list>  
#include<iostream> 
#include<assert.h>
#include<vector> 
#include<stack>
#include<stdlib.h>
using namespace std; 
 
/* programm1:
������������ n �� m��������1��2��3.......n �� ����ȡ������,
ʹ��͵��� m ,Ҫ���������еĿ�������г���.
*/
void try_find_factor(); 
list<int>list1;
/*programm2

	����������ת
*/
void reverse_single_link_list();

struct ListNode
{
	int data;
	ListNode *next;
};
ListNode* head;
ListNode*  Create();
void DisplayList(ListNode* head);
ListNode* ReverseList(ListNode* head);
/*programm3:

�������������Ϊ˫����������
*/
void  changebstree_to_doublelink();
struct BSTreeNode
{
    int m_nValue; // value of node
    BSTreeNode *m_pLeft; // left child of node
    BSTreeNode *m_pRight; // right child of node
};
void addBSTreeNode(BSTreeNode *&pCurrent,int value);
void inOrderBSTree(BSTreeNode* pBSTree);
void convertToDoubleList(BSTreeNode* pCurrent);
void inorderbeforechange(BSTreeNode* pCurrent);
BSTreeNode *pHead=NULL;//ָ��ѭ������ͷ���
BSTreeNode *pIndex=NULL;//ָ��ǰһ�����
/*programm4:
	����ջ�����ݽṹ��Ҫ�����һ��min�������ܹ��õ�ջ����СԪ�ء�Ҫ����min��push�Լ�pop��ʱ�临�Ӷȶ���O(1)��
*/
void anotherstack();
/*programm5
	����һ���������飬������������Ҳ�и�����
������������һ�������������һ�������飬ÿ�������鶼��һ���͡�
������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��
*/
void findmaxsubarray();

/*programm6
	����һ��������һ�ö�Ԫ���������ĸ���㿪ʼ���·���һֱ��Ҷ��������������н���γ�һ��·����
��ӡ����������������ȵ�����·����
*/
void tryfindpath();
void findpath(const BSTreeNode* pTreeNode,const int expectedSum,vector<int>& path,int & currentSum);
/*programm7
����n�����������������С��k����
��������1��2��3��4��5��6��7��8��8�����֣�
����С��4������Ϊ1��2��3��4��

*/
void findminimumk();
/*programm8
	����10����ʱ�䣬�������Ÿ���ʮ�������������������Ӧ��ʮ����  
Ҫ������ÿ����������ǰ������ʮ���������ų��ֵĴ�����  
*/
void findfrequency();

/*programm9
�����������������ͷָ�룬����h1��h2���ж������������Ƿ��ཻ
*/
/*
	programm10
	�ж����������ǲ��Ƕ�Ԫ�������ĺ���������
��Ŀ������һ���������飬�жϸ������ǲ���ĳ��Ԫ�������ĺ�������Ľ����
����Ƿ���true�����򷵻�false��
*/
bool verifusqeuenceofBST(int sequence[],int length);
void verify();
/*
	programm11
	���ʷ�ת
*/
class ReverseWords;
void reverseword();

/*
	��������нڵ��������...
*/
int maxD;
int maxDistance(BSTreeNode*	p);
void getmaxdistance();

void find_factor(int sum, int n)   
{  
    // �ݹ����  
    if(n <= 0 || sum <= 0)  
        return;  
      
    // ����ҵ��Ľ��  
    if(sum == n)  
    {  
        // ��תlist  
        list1.reverse();  
        for(list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)  
            cout << *iter << " + ";  
        cout << n << endl;  
        list1.reverse();      
    }  
      
    list1.push_front(n);      //���͵�01��������  
    find_factor(sum-n, n-1);   //��n��n-1��������sum-n  
    list1.pop_front();  
    find_factor(sum, n-1);     //����n��n-1��������sum   
}  
void try_find_factor()
{
	int sum, n;  
    cout << "input the sum:" << endl;  
    cin >> sum;  
    cout << "input the n:" << endl;  
    cin >> n;  
    cout << "the choice:" << endl;  
    find_factor(sum,n);   
} 


ListNode*  Create()
{//start of CREATE()
	ListNode* p=NULL;
	ListNode* q=NULL;
	head=NULL;
	int Time;
	cout<<"Please input the length of the movie."<<endl;
	cin>>Time;
	while(Time!=0){
	p=new ListNode;
	//���Ʊ��:  TreeNode* node = new TreeNode;//Noice that [new] should be written out.
	p->data=Time;

	if(head==NULL)
	{
	head=p;
	}
	else
	{
	q->next=p;
	}
	q=p;
	cout<<"Please input the length of the movie."<<endl;
	cin>>Time;
	}
	if(head!=NULL)
	q->next=NULL;
	return head;

}//end of CREATE()


void DisplayList(ListNode* head)
{//start of display
	cout<<"show the list of programs."<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head=head->next;
	}
}//end of display


ListNode* ReverseList(ListNode* head)
{
	ListNode* p;
	ListNode* q;
	if(!head||!head->next) return head;/// empty or just one node;
	p=head->next;
	while(p->next!=NULL){
		q=p->next;
		p->next=q->next;
		q->next=head->next;
		head->next=q;
	}

	p->next=head;//�൱�ڳɻ�
	head=p->next->next;//��head��Ϊԭhead��next
	p->next->next=NULL;//�ϵ���
	return head;  
}

void reverse_single_link_list()
{
	DisplayList(ReverseList(Create()));
}

void addBSTreeNode(BSTreeNode *&pCurrent,int value)//����������л�Ҫ�ı�ָ��ֵ��һ��Ҫ�ǵ�ʹ�����ô���
{
    if (pCurrent==NULL)
    {
        BSTreeNode* pBSTree=new BSTreeNode();
        pBSTree->m_nValue=value;
        pBSTree->m_pLeft=NULL;
        pBSTree->m_pRight=NULL;
        pCurrent=pBSTree;
    }
    else if (pCurrent->m_nValue<value)
    {
        addBSTreeNode(pCurrent->m_pRight,value);
    }
    else if (pCurrent->m_nValue>value)
    {
        addBSTreeNode(pCurrent->m_pLeft,value);
    }
    else
    {
        cout<<"node repeated"<<endl;
    }
 
}
void inorderbeforechange(BSTreeNode* pCurrent)
{
	if(pCurrent->m_pLeft)
		inorderbeforechange(pCurrent->m_pLeft);
	if(pCurrent)
		cout<<pCurrent->m_nValue<<"\t";
	if(pCurrent->m_pRight)
		inorderbeforechange(pCurrent->m_pRight);
}
void inOrderBSTree(BSTreeNode* pBSTree)
{
 
    if (NULL==pBSTree)
    {
        return;
    }
    if (NULL!=pBSTree->m_pLeft)
    {
        inOrderBSTree(pBSTree->m_pLeft);
    }
    convertToDoubleList(pBSTree);
 
    if (NULL!=pBSTree->m_pRight)
    {
        inOrderBSTree(pBSTree->m_pRight);
    }
 
}
/************************************************************************/
 
/************************************************************************/
/* �������ָ��                                                                   */
void convertToDoubleList(BSTreeNode* pCurrent)
{
    pCurrent->m_pLeft=pIndex;//ʹ��ǰ������ָ��ָ��˫�����������һ�����
    if (NULL==pIndex)//�����һ��Ԫ�ز����ڣ���ʱ˫��������δ��������˽���ǰ�����Ϊ˫������ͷ���
    {
        pHead=pCurrent;
    }
    else//ʹ˫�����������һ��������ָ��ָ��ǰ���
    {
        pIndex->m_pRight=pCurrent;
    }
 
    pIndex=pCurrent;//����ǰ�����Ϊ˫�����������һ�����
 
    //cout<<pCurrent->m_nValue<<" ";
 
}
void changebstree_to_doublelink()
{
	BSTreeNode *pRoot=NULL;
	int i=0;
	for(i;i<10;i++)
		addBSTreeNode(pRoot,i*2);
	cout<<"inorder befor change\n";
	inorderbeforechange(pRoot);
	cout<<endl;
	inOrderBSTree(pRoot);
	BSTreeNode*temp=pRoot;
	cout<<"after change\n";
	while(NULL!=temp)
	{
		cout<<temp->m_nValue<<'\t';
		temp=temp->m_pRight;
	}
	cout<<endl;
}

/// programm4:
template <typename T> class CStackWithMin
{
public:
      CStackWithMin() {}
      virtual ~CStackWithMin(void) {}

      T& top(void);
      const T& top(void) const;

      void push(const T& value);
      void pop(void);

      const T& min(void) const;

private:
     vector<T> m_data;               // the elements of stack
     vector<size_t> m_minIndex;      // the help stack
};

// get the last element of mutable stack
template <typename T> T& CStackWithMin<T>::top()
{
	cout<<"the data in m_minIndex is:"<<m_minIndex.back()<<endl;
    return m_data.back();
}

// get the last element of non-mutable stack
template <typename T> const T& CStackWithMin<T>::top() const
{
      cout<<"the data in m_minIndex is:"<<m_minIndex.back()<<endl;
	  return m_data.back();
}

// insert an elment at the end of stack
template <typename T> void CStackWithMin<T>::push(const T& value)
{
      // append the data into the end of m_data
      m_data.push_back(value);

      // set the index of minimum elment in m_data at the end of m_minIndex
      if(m_minIndex.size() == 0)
            m_minIndex.push_back(0);
      else
      {
            if(value < m_data[m_minIndex.back()])
                  m_minIndex.push_back(m_data.size() - 1);
            else
                  m_minIndex.push_back(m_minIndex.back());
      }
}

// erease the element at the end of stack
template <typename T> void CStackWithMin<T>::pop()
{
      // pop m_data
      m_data.pop_back();

      // pop m_minIndex
      m_minIndex.pop_back();
}

// get the minimum element of stack
template <typename T> const T& CStackWithMin<T>::min() const
{
      assert(m_data.size() > 0);
      assert(m_minIndex.size() > 0);

      return m_data[m_minIndex.back()];
}
void anotherstack()
{
	CStackWithMin<int> csstack;
	int i=0;
	for(i;i<10;i++)
		csstack.push(9-i);
	cout<<csstack.top()<<endl;
}
bool maxSubarray(const vector<int>data,int &max,int index[]) 
{
    if (data.size()<=0) 
    {
		cout<<"error array size\n";
        return false;
    }
    int sum = 0;
	int i=0;
    max=-(1<<30);
    for(i;i<data.size();i++)
    {
       sum +=data[i];
       if(sum>max)
       {
            max=sum;
			index[1]=i;
       }
       else if(sum<0)
      {
           sum=0;
		   index[0]=i+1;
      }
   }
   return true;
}
void findmaxsubarray()
{
	vector<int>data{1, -2, 3, 10, -4, 7, 2, -5,7,-5,8};
	int index[]={0,0};
	int max;
	int i;
	if( maxSubarray(data,max,index))
	{
		cout<<"the max is:"<<max<<endl;
		cout<<"the subarray is:\n";
		for(i=index[0];i<=index[1];i++)
			cout<<data[i]<<'\t';
		cout<<endl;
	}
}

void findpath(const BSTreeNode* pTreeNode,const int expectedSum,vector<int>& path,int & currentSum)
{
	if( !pTreeNode )
        return;
    currentSum += pTreeNode->m_nValue;
    path.push_back(pTreeNode->m_nValue);
    bool isLeaf = !(pTreeNode->m_pLeft) && !(pTreeNode->m_pRight);
    if(currentSum == expectedSum && isLeaf)
    {   
		for(auto &c:path)
			cout<<c<<'\t';;
        cout << endl;
    }   
    if(pTreeNode->m_pLeft)
        findpath(pTreeNode->m_pLeft, expectedSum, path, currentSum);
    if(pTreeNode->m_pRight)
        findpath(pTreeNode->m_pRight, expectedSum, path, currentSum);

    currentSum -= pTreeNode->m_nValue;
    path.pop_back();
}
void tryfindpath()
{
	BSTreeNode* T=NULL;
	int max=101,min=0,randomdata;
	int i=0;
	addBSTreeNode(T,10);
	addBSTreeNode(T,12);
	addBSTreeNode(T,5);
	addBSTreeNode(T,7);
	addBSTreeNode(T,4);
	addBSTreeNode(T,1);
	addBSTreeNode(T,2);
	
	vector<int> path;
    int sum = 0;
    findpath(T, 22, path, sum);
}


/*programm7

*/
class MinK{
public:
    MinK(int *arr,int si):array(arr),size(si){}
    bool kmin(int k,int*& ret);
    void remove(int*& ret)
	{
        delete[] ret;
        ret=NULL;
    }
     
private:
    void shiftDown(int *ret,int pos,int length);
    int *array;
    int size;
};
bool MinK::kmin(int k,int *&ret)
{
     if(k>size)
      {
        ret=NULL;
        return false;
      }
      else
      {
         ret=new int[k--];
         int i;
         for(i=0;i<=k;++i)
            ret[i]=array[i];
         for(int j=(k-1)/2;j>=0;--j)
            shiftDown(ret,j,k);
         for(;i<size;++i)
            if(array[i]<ret[0])
            {
                ret[0]=array[i];
                shiftDown(ret,0,k);
            }
        return true;
       }
}
void MinK::shiftDown(int *ret,int pos,int length)
{
        int t=ret[pos];
        for(int s=2*pos+1;s<=length;s=2*s+1)
		{
            if(s<length&&ret[s]<ret[s+1])
                ++s;
            if(t<ret[s])
            {
                ret[pos]=ret[s];
                pos=s;
            }
            else break;
        }
      ret[pos]=t;
}
void findminimumk()
{
	int array[]={1,2,3,4,5,6,7,8,9,10,11,12};
    MinK mink(array,sizeof(array)/sizeof(array[0]));
    int *ret;
    int k=6;
    if(mink.kmin(k,ret))
    {
        for(int i=0;i<k;++i)
            cout<<ret[i]<<endl;
        mink.remove(ret);
    }
}
/*programm8
*/

#define		MAX_LEN	1000

class C_NumberTB
{
	private:
		int m_aryTop[MAX_LEN];
		int m_aryBottom[MAX_LEN];
		bool m_success;

	public:
		C_NumberTB();
		int* GetBottom();
		void SetNextBottom();
		int GetFrequecy(int nValue);
};

C_NumberTB::C_NumberTB()
{
	m_success = false;

	//format top
	for(int i = 0; i < MAX_LEN; i++)
	{
		m_aryTop[i] = i;
		m_aryBottom[i] = i;
	}
}

int* C_NumberTB::GetBottom()
{
	int i = 0;
	while(!m_success)
	{
		i++;
		SetNextBottom();
	}
	cout<<"try "<<i<<" times"<<endl;
	return m_aryBottom;
}

//set next bottom
void C_NumberTB::SetNextBottom()
{
	bool bRet = true;

	for(int i = 0; i < MAX_LEN; i++)
	{
		int nFreq = GetFrequecy(i);
		if(m_aryBottom[i] != nFreq)
		{
			m_aryBottom[i] = nFreq;
			bRet = false;
		}
	}

	m_success = bRet;
}
//get frequency in bottom
int C_NumberTB::GetFrequecy(int nValue) //�˴���nValue ��ָ���ŵ���i
{
	int nCnt = 0;
	for(int  i = 0; i < MAX_LEN; i++)
	{
		if(m_aryBottom[i] == nValue)
			nCnt++;
	}

	return nCnt; //nCnt ����ӦnFreq
}
void findfrequency()
{
	C_NumberTB objTB;
	int* pResult = objTB.GetBottom();

	for(int  i= 0 ;i < MAX_LEN; i++)
	{
		cout << *pResult++ <<'\t';
	}
	cout<<endl;

}
bool verifusqeuenceofBST(int squence[],int length)
{
	if(squence == NULL || length <= 0)
		return false;

      // root of a BST is at the end of post order traversal squence
      int root = squence[length - 1];

      // the nodes in left sub-tree are less than the root
      int i = 0;
      for(; i < length - 1; ++ i)
      {
            if(squence[i] > root)
                  break;
      }

      // the nodes in the right sub-tree are greater than the root
      int j = i;
      for(; j < length - 1; ++ j)
      {
            if(squence[j] < root)
                  return false;
      }

      // verify whether the left sub-tree is a BST
      bool left = true;
      if(i > 0)
            left = verifusqeuenceofBST(squence, i);

      // verify whether the right sub-tree is a BST
      bool right = true;
      if(i < length - 1)
            right = verifusqeuenceofBST(squence + i, length - i - 1);

      return (left && right);
}
void verify()
{
	int seq[7]={5,7,6,9,11,10,8};
	if(verifusqeuenceofBST(seq,7))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}


/// reverseword

class ReverseWords{
public:
    ReverseWords(string* wo):words(wo){}
    void reverse()
    {
        int length=words->size();
        int begin=-1,end=-1;
        for(int i=0;i<length;++i){
            if(begin==-1&&words->at(i)==' ')
                continue;
            if(begin==-1)
            {
                begin=i;
                continue;
            }
            if(words->at(i)==' ')
                end=i-1;
            else if(i==length-1)
                end=i;
            else 
				continue;
            reverse__(begin,end);    //1.���ʷ�ת
            begin=-1,end=-1;           
        }
        reverse__(0,length-1);       //2.���е��ַ���ת
    }

	private:
		void reverse__(int begin,int end)   //
		{
			while(begin<end)               
			{
				char t=words->at(begin);
				words->at(begin)=words->at(end);
				words->at(end)=t;
				//words[begin];
				//words[begin]=words[end];
				//words[end]=t;
				++begin;
				--end;
			}
		}
    string* words;
};
class ReverseWords2{   /// by zgw
public:
    ReverseWords2(string wo):words(wo){}
    void reverse()
    {
        int length=words.size();
        int begin=-1,end=-1;
        for(int i=0;i<length;++i){
            if(begin==-1&&words[i]==' ')
                continue;
            if(begin==-1)
            {
                begin=i;
                continue;
            }
            if(words[i]==' ')
                end=i-1;
            else if(i==length-1)
                end=i;
            else 
				continue;
            reverse__(begin,end);    //1.���ʷ�ת
            begin=-1,end=-1;           
        }
        reverse__(0,length-1);       //2.���е��ַ���ת
    }

	private:
		void reverse__(int begin,int end)   //
		{
			while(begin<end)               
			{
				//char t=words->at(begin);
				//words->at(begin)=words->at(end);
				//words->at(end)=t;
				char t=words[begin];
				words[begin]=words[end];
				words[end]=t;
				++begin;
				--end;
			}
		}
    string& words;
};
void  reverseword(){
    string s="I  am a student.";
    ReverseWords2 *r=new ReverseWords2(s);
    r->reverse();
	delete r;
    cout<<s<<endl;
	//s[0]='a';
	//cout<<s<<endl;
}

int maxDistance(BSTreeNode*	p)
{
	if(p == NULL)
		return 0;
	if(p->m_pLeft== NULL && p->m_pRight == NULL){
		return 0;
	}

	int ln = 0;
	int rn = 0;
	if(p->m_pLeft != NULL)
		ln = 1 + maxDistance(p->m_pLeft);
	if(p->m_pRight != NULL)
		rn = 1 + maxDistance(p->m_pRight);

	int diff = ln + rn;
	maxD = maxD>diff?maxD:diff;
	return (ln>rn)?ln:rn;
}
void getmaxdistance()
{
	BSTreeNode* T=NULL;
	addBSTreeNode(T,10);
	addBSTreeNode(T,12);
	addBSTreeNode(T,5);
	addBSTreeNode(T,7);
	addBSTreeNode(T,4);
	addBSTreeNode(T,1);
	addBSTreeNode(T,2);
	addBSTreeNode(T,15);
	addBSTreeNode(T,18);
	inorderbeforechange(T);
	cout<<endl;
	if(maxDistance(T)!=0)
		cout<<"maxdistance is "<<maxD<<endl;
	
}

int main()  
{  
    //try_find_factor();
	//reverse_single_link_list();
	//changebstree_to_doublelink();
	//anotherstack();
	//findmaxsubarray();
	//tryfindpath();
	//findminimumk();
	//findfrequency();
	//verify();
	//reverseword();
	getmaxdistance();
	
}  