//infix prefix postfix
// matrix 


#include<iostream>
#include<cmath>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Complex{
    double real,img;
    public:
        Complex(){}
        Complex(double a,double b): real(a),img(b){}

        friend Complex add(Complex c1,Complex c2){
            return Complex(c1.real + c2.real , c1.img + c2.img);
        }

        friend Complex subtract(Complex c1,Complex c2){
            return Complex(c1.real - c2.real , c1.img - c2.img);
        }
        friend Complex multiply(Complex c1,Complex c2){
            Complex res;
            res.real = c1.real*c2.real - c1.img*c2.img;
            res.img = c1.real*c2.img + c1.img*c2.real;
            return res;
        }
        friend Complex divide(Complex c1,Complex c2){
            if(c2.real == 0 && c2.img == 0){
                throw "Exception : Modulus of 2nd Complex number is zero. Invalid";
            }
            Complex res;
            res.real = (c1.real*c2.real + c1.img*c2.img)/(c2.real*c2.real + c2.img*c2.img);
            res.real = (c1.real*c2.img - c1.img*c2.real)/(c2.real*c2.real + c2.img*c2.img);
            return res;
        }

        
        friend istream& operator >>(istream& in,Complex&z){
            cout<<"Enter real part: ";
            in>>z.real;
            cout<<"Enter imaginary part: ";
            in>>z.img;
            return in;
        }
        friend ostream& operator <<(ostream& out,Complex&z){
            if(z.img >= 0)
                out<<z.real<<" + "<<z.img<<"i"<<endl;
            else
                out<<z.real<<" - "<<(-1*z.img)<<"i"<<endl;

            return out;
        }

};

class calulator{
    double a, b;
    public:
    calulator(double x,double y): a(x),b(y){}
    double add(){
        return a+b;
    }
    double subtract(){
        return a-b;
    }
    double multiply(){
        return a*b;
    }
    double divide(){
        if(b==0) throw "Exception : division by 0";
        return a/b;
    }
    double power(){
        return pow(a,b);
    }
};

class matrix{
    vector<vector<int>> input(){
        cout<<"Enter the number of Rows and Columns respectively.";
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        cout<<"Enter the Matrix"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        return a;
    }
    void print(const vector<vector<int>>& a){
        cout<<"Result:"<<endl;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    public:
    void scalarMultiplication(){
        vector<vector<int>> mat = input();
        cout<<"Enter the scaler to multiply the matrix with: ";
        int k;
        cin>>k;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j] *= k;
            }
        }
        print(mat);
    }
    void add(){
        cout<<"For martix 1"<<endl;
        vector<vector<int>> m1 = input();
        cout<<"For martix 2"<<endl;
        vector<vector<int>> m2 = input();
        if(m1.size() != m2.size() || m1[0].size() != m2[0].size() ){
            throw "Exception : Matix size dont match";
        }
        for(int i=0;i<m1.size();i++){
            for(int j=0;j<m1[0].size();j++){
                m1[i][j] += m2[i][j];
            }
        }
        print(m1);
    }
    void subtract(){
        cout<<"For martix 1"<<endl;
        vector<vector<int>> m1 = input();
        cout<<"For martix 2"<<endl;

        vector<vector<int>> m2 = input();
        if(m1.size() != m2.size() || m1[0].size() != m2[0].size()){
            throw "Exception : Matix size dont match";
        }
        for(int i=0;i<m1.size();i++){
            for(int j=0;j<m1[0].size();j++){
                m1[i][j] -= m2[i][j];
            }
        }
        print(m1);
    }

    void matrixMultiplication(){
        cout<<"For martix 1"<<endl;
        vector<vector<int>> m1 = input();
        cout<<"For martix 2"<<endl;

        vector<vector<int>> m2 = input();

        if(m2.size() != m1[0].size()){
            throw "Exception : Invalid Matix size";
        }
        vector<vector<int>> res(m1.size(),vector<int>(m2[0].size()));

        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[0].size();j++){
                for(int k=0;k<m2.size();k++){
                    res[i][j] += m1[i][k]*m2[k][j];
                }
            }
        }
        print(res);
    }
};

void calculate(string s) {

    stack<int> stk;
    int num=0;
    int res=0;
    int sign=1;
    for(char ch : s){
        if(isdigit(ch)){
            num = num*10 + (ch-'0');
        }else if(ch=='+'){
            res += (sign*num);
            num=0;
            sign=1;
        }else if(ch=='-'){
            res += (sign*num);
            num=0;
            sign=-1;
        }else if(ch=='('){
            stk.push(res);
            stk.push(sign);
            res=0;
            num=0;
            sign=1;
        }else if(ch==')'){
            res += (num*sign);
            num=0;
            int st_sign = stk.top(); stk.pop();
            int last_res = stk.top(); stk.pop();

            res *= st_sign;
            res += last_res;
        }
        else if(!isspace(ch)){
            throw "Invalid Expression";
        }
    }
    res += (num*sign);
    cout<<"Result: "<<res<<endl;
}



int main(){
    cout<<"Welcome To Calculator"<<endl;
    int choice;
    cout<<"In Which field do you want to work on?"<<endl;
    cout<<"1.Basic Calculator"<<endl;
    cout<<"2.Complex Calculator"<<endl;
    cout<<"3.Matrix Calculator"<<endl;
    cout<<"4.Expression Evaluator"<<endl;
    cout<<"Enter Your choice:"<<endl;
    cin>>choice;

    if(choice == 1){
        double x,y;
        cout<<"Enter Expression (like 5+2)"<<endl;
        char op;
        cin>>x>>op>>y;

        calulator cal = calulator(x,y);
        cout<<"Result: ";
        try{
            switch(op){
                case '+': cout<< cal.add();
                            break;
                case '-': cout<< cal.subtract();
                            break;
                case '*': cout<< cal.multiply();
                            break;
                case '/': cout<< cal.divide();
                            break;
                case '^': cout<< cal.power();
                            break; 
                default:
                    cout<<"Exception: Invalid Input";
                    break;
            }
        }
        catch(const char* msg){
            cout<<msg<<endl;
        }
    }
    else if(choice == 2){
        Complex x,y;
        cout<<"Enter Expression"<<endl;
        char op;
        cin>>x;
        cout<<"Enter Operator: ";
        cin>>op;
        cin>>y;
        Complex temp;
        try{
            switch(op){
                case '+':   temp = add(x,y);
                            cout<< temp;
                            break;
                case '-':   temp = subtract(x,y);
                            cout<< temp;
                            break;
                case '*':   temp = multiply(x,y);
                            cout<< temp;
                            break;
                case '/':   temp = divide(x,y);
                            cout<< temp;
                            break;
                default:
                    cout<<"Exception: Invalid Input";
                    break;
            }
        }catch(const char* msg){
            cout<<msg<<endl;
        }

    }
    else if(choice == 3){
        int c;
        cout<<"1.Matirx Addtion."<<endl;
        cout<<"2.Matirx Subtraction."<<endl;
        cout<<"3.Matirx Multiplication."<<endl;
        cout<<"4.Matirx Scaler Multiplication."<<endl;
        cout<<"Enter your choice: ";
        cin>>c;
        matrix m;
        try{
            switch(c){
                case 1: m.add(); 
                        break;
                case 2: m.subtract();
                        break;
                case 3: m.matrixMultiplication();
                        break;
                case 4: m.scalarMultiplication();
                        break;
                default:
                    cout<<"Exception: Invalid Input";
                    break;
            }
        }catch(const char * msg){
            cout<<msg<<endl;
        }
    }
    else if(choice == 4){
        cout<<"Enter the expression...Please Note: Experssion containing + - and () are solved"<<endl;
        string exp;
        cin>>exp;
        try{
            calculate(exp);
        }catch(const char*msg){
            cout<<msg<<endl;
        }
    }
    else{
        cout<<"Exception: Invalid Input";
    }
    return 0;
}