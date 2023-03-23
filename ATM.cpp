#include <iostream>
#include <string>
#include<conio.h>
using namespace std;

class ATM_abstract
{
    protected:
    long long int account_no, mobile;
    int pin;
    string name;
    float balance;
    
    public:
    virtual void updateMobile(long long int, long long int) = 0;
    
    void setAcc(long long int account_no)                //setters
    {
          this->account_no = account_no;
    }
    void setMobile(long long int mobile)
    {
        this->mobile = mobile;
    }
    void setPin(int pin)
    {
        this->pin = pin;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setBalance(float balance)
    {
        this->balance = balance;
    }
    long long int getAcc()                           //gettters
    {
        return this->account_no;
    }
    string getName()
    {
        return this->name;
    }
    int getPin()
    {
        return this->pin;
    }
    float getBalance()
    {
        return this->balance;
    }
    long long int getMobile()
    {
        return this->mobile;
    }
};
class ATM_Base : public ATM_abstract
{
    public:
    virtual void updateMobile(long long int , long long int)
    {   }
    virtual void cashDeposit(float )
    {   }
    virtual void cashWithdraw(float )
    {   }
    ATM_Base(string name,long long int mobile,long long int acc,int pin, double balance)
    {
       setAcc(acc);
       setName(name);
       setMobile(mobile);
       setPin(pin);
       setBalance(balance);
    }
};
class Functions : public ATM_Base
{
    public:
    void updateMobile(long long int pre_mobile,long long int new_mobile)
    {
        if (pre_mobile == this->mobile)
        { 
            this->mobile = new_mobile;
            cout << "Succesfully updated Mobile number.";
            _getch();
        }
        else
        {
            cout << "Incorrect Old Mobile number. Please try again.";
            _getch();
        }
    }

    void cashDeposit(float amount)
    {
        if (amount > 0)
        { 
            this->balance = this->balance + amount;
            cout << "Succecfull!!" << endl;
            cout << "Available Balance : " << this->balance;
            _getch();
        }
        else
        {
            cout << "Invlaid Input. Please try again.";
            _getch();
        }
    }
    void cashWithdraw(double amount)
    {
        if (amount > 0 && amount <= this->balance)
        { 
            this->balance = this->balance - amount;
            cout << "Please collect your Cash." << endl;
            cout << "Available Balance : " << this->balance;
            _getch();
        }
        else
        {
            cout << " Invalid Input or Insufficient Balance.";
            _getch();
        }
    }
};

int main()
{
    int choice = 0, enterPin;
    long long int account_no;
    ATM_Base obj[15] =   {  
                        ATM_Base("Amit kumar",9823847289,8733245,1021,8732.32),
                        ATM_Base("Shivam Pandey",9883940873,3982382,5212,83243.34),
                        ATM_Base("Ankit",983294092,7334593,2923,2334.32),
                        ATM_Base("Piyush",423653424,2343443,2322,32434.43),
                        ATM_Base("Sushil",87326292,3423374,8727,254543.54),
                        ATM_Base("Rushi",352343443,3443676,4353,45323.32),
                        ATM_Base("Krishna",3244243543,5845401,9884,77345.54),
                        ATM_Base("Swapnil",988347988,7343487,3432,34544.54),
                        ATM_Base("Pratyaksh",988374339,8773687,3423,54353.34),
                        ATM_Base("Varun",982391220,2732354,2324,87734.34),
                        ATM_Base("Rajesh",983274633,2633345,8736,98834.43),
                        ATM_Base("Haward",932462398,8732223,3334,37743.34),
                        ATM_Base("Lenard",988327493,8338787,6533,21343.34),
                        ATM_Base("Sheldon",2735812323,8343411,2349,309432.33),
                        ATM_Base("Kailash",983274922,4334393,9834,398440.43)
                        };
    do
    {
    system("cls");
        cout << "__________________Welcome to ATM________________" << endl<<endl;
        cout << "Enter the Account number :-  ";
        cin >> account_no;
        cout << "Enter the PIN :- ";
        cin >> enterPin;
        for(int i=0; i<15; i++){
        if ( i<=14 && account_no == obj[i].getAcc() && enterPin == obj[i].getPin())
        {

            do
            {
                double amount;
                long long int old_mobile, new_mobile;
                system("cls");


                cout << "__________________Welcome to ATM________________" << endl<<endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Deposit Money" << endl;
                cout << "3. Withdraw Money" << endl;
                cout << "4. Account Details" << endl;
                cout << "5. Update Mobile Number" << endl;
                cout << "6. Exit" << endl;
                cin >> choice;

                switch (choice)
                {
                 case 1:
                    cout << "Your Account Balance : " << obj[i].getBalance() << endl;
                    _getch();
                    break;
                 case 2:
                    cout << "Enter the Amount for deposit : ";
                    cin >> amount;
                    obj[i].cashDeposit(amount);
                    _getch();
                    break;
                case 3:
                    cout << "Enter the Amount for witgdrawing : ";
                    cin >> amount;
                    obj[i].cashWithdraw(amount);
                    _getch();
                    break;
                case 4:
                    cout << "___________User's Details_____________" << endl;
                    cout << "Account Name : " << obj[i].getName() << endl;
                    cout << "Account  No. : " << obj[i].getAcc() << endl;
                    cout << "Balance : " << obj[i].getBalance() << endl;
                    cout << "Mobile No. : " << obj[i].getMobile() << endl;
                    _getch();
                    break;
                 case 5:
                    cout << "Enter Old Mobile No. : ";
                    cin >> old_mobile;
                    cout << "Enter New Mobile No. : ";
                    cin >> new_mobile;
                    obj[i].updateMobile(old_mobile, new_mobile);
                    break;
                 case 6:
                    exit(0);
                    break;   
                }
            }
            while(1);
        }   
        if(i==14 && account_no != obj[i].getAcc() && enterPin != obj[i].getPin())
        {
            cout << "User's Details is Invalid. Please try again." << endl;
            break;
            _getch();
        }
    } 
    }
    while (1);
     return 0;
}
