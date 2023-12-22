#include<iostream>
#include<string.h>
using namespace std;

#define MAX 50

class Stack //Stack Data Structure and its methods
{
private:
    char data[MAX],str[MAX];
    int top,length,count;
    void pushData(char);
    char popData();

public:
    Stack()
    {
        top=-1;
        length=0;
        count=0;
    }
    void getString();
    void checkPalindrome();
    void extractString();
    void displayReverse();
};

int main()
{
    Stack obj;
    obj.getString();
    obj.extractString();
    cout<<"\nString is extracted after removing the punctuations and symbols."<<endl;
    cout<<"\nString is converted to lower case !"<<endl;
    cout<<"\nReverse of the entered string is : ";
    obj.displayReverse();
    obj.checkPalindrome();

    return 0;

}

void Stack::getString()
{
    cout<<"\nEnter a string : ";
    cin.getline(str,MAX);
    length = strlen(str);
}

void Stack::extractString()
{
    char temp[MAX];

    for(int i=0;i<length;i++)
    {
        temp[i]=str[i];
    }

    int j=0;

    for(int i=0;i<length;i++)
    {
        if(isalpha(temp[i]))
        {
            str[j]=tolower(temp[i]);
            j++;
        }
    }
    length=j;
}

void Stack::checkPalindrome()
{
    for(int i=0;i<length;i++)
    {
        pushData(str[i]);
    }
    for(int i=0;i<length;i++)
    {
        if(str[i]==popData())
        {
            count++;
        }
    }
    if(count==length)
    {
        cout<<"\n\nEntered String is a Palindrome. \n"<<endl;
    }
    else
        cout<<"\n\nEntered string is not a Palindrome. \n"<<endl;

}

void Stack::displayReverse()
{
    for(int i=length-1;i>=0;i--)
    {
        cout<<str[i];
    }
}

void Stack::pushData(char temp)
{
    if(top==MAX-1)
    {
        cout<<"\n Stack Overflow!!!"<<endl;
        return ;
    }
    top++;
    data[top]=temp;
}

char Stack::popData()
{
    if(top==-1)
    {
        cout<<"\n Stack Underflow!!!"<<endl;
        char ch='\n';
        return ch;
    }
    char temp = data[top];
    top--;
    return temp;
}
