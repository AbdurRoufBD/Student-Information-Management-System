#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct student
{
    int id;
    string name;
    string fname;
    string mname;
    string gender;
    string email;
    string pnumber;
    string bdate;
    string flink;
    string bgroup;
};


vector<student> students;

void CreateDatabase()
{
    FILE *fp;
    fp = fopen("database","w");
    fclose(fp);
}

void LoadStudentInfoFromFile()
{
    FILE* file;
    file = fopen("database","r");
    //if(file==NULL) cout<<"NULL"<<endl;
    if ( file != NULL )
    {
        char line [ 1000 ]; /* or other suitable maximum line size */
        int lineNo = 1;
        student stdt;
        while ( fgets ( line, sizeof (line), file ) != NULL )
        {
            string temp = line;
            temp[temp.size()-1]='\0';

            switch(lineNo%10)
            {
            case 1:
                stdt.id = atoi(temp.c_str());
                break;
            case 2:
                stdt.name = temp;
                break;
            case 3:
                stdt.fname = temp;
                break;
            case 4:
                stdt.mname = temp;
                break;
            case 5:
                stdt.gender = temp;
                break;
            case 6:
                stdt.email = temp;
                break;
            case 7:
                stdt.pnumber = temp;
                break;
            case 8:
                stdt.bdate = temp;
                break;
            case 9:
                stdt.flink = temp;
                break;
            case 0:
                //cout<<"Hi"<<endl;
                stdt.bgroup = temp;
                students.push_back(stdt);
                break;
            default :
                break;
            }

            lineNo++;
        }

        fclose ( file );
    }
}

void PrintInConsole()
{
    int len = students.size();
    for(int i = 0; i < len; i++)
    {
        cout<<"____________________________________________________________"<<endl;
        cout<<"Student ID \t\t: "<<students[i].id<<endl;
        cout<<"Name \t\t\t: "<<students[i].name<<endl;
        cout<<"Father's Name \t\t: "<<students[i].fname<<endl;
        cout<<"Mother's Name \t\t: "<<students[i].mname<<endl;
        cout<<"Gender \t\t\t: "<<students[i].gender<<endl;
        cout<<"Email Address \t\t: "<<students[i].email<<endl;
        cout<<"Phone Number \t\t: "<<students[i].pnumber<<endl;
        cout<<"Date of Birth \t\t: "<<students[i].bdate<<endl;
        cout<<"Facebook profile link \t: "<<students[i].flink<<endl;
        cout<<"Blood group \t\t: "<<students[i].bgroup<<endl;
    }
}

void PrintInFile()
{
    FILE *file;
    file = fopen("database","w");
    int len = students.size();
    for(int i = 0; i < len; i++)
    {
        fprintf(file,"%d\n",students[i].id);
        fprintf(file,"%s\n",students[i].name.c_str());
        fprintf(file,"%s\n",students[i].fname.c_str());
        fprintf(file,"%s\n",students[i].mname.c_str());
        fprintf(file,"%s\n",students[i].gender.c_str());
        fprintf(file,"%s\n",students[i].email.c_str());
        fprintf(file,"%s\n",students[i].pnumber.c_str());
        fprintf(file,"%s\n",students[i].bdate.c_str());
        fprintf(file,"%s\n",students[i].flink.c_str());
        fprintf(file,"%s\n",students[i].bgroup.c_str());
    }

    fclose(file);
}

void PrintReport()
{
    FILE *file;
    file = fopen("students.txt","w");
    int len = students.size();
    for(int i = 0; i < len; i++)
    {
        fprintf(file,"______________________________________\n");
        fprintf(file,"Student ID \t\t: %d\n",students[i].id);
        fprintf(file,"Name \t\t\t: %s\n",students[i].name.c_str());
        fprintf(file,"Father's Name \t\t: %s\n",students[i].fname.c_str());
        fprintf(file,"Mother's Name \t\t: %s\n",students[i].mname.c_str());
        fprintf(file,"Gender \t\t\t: %s\n",students[i].gender.c_str());
        fprintf(file,"Email Address \t\t: %s\n",students[i].email.c_str());
        fprintf(file,"Phone Number \t\t: %s\n",students[i].pnumber.c_str());
        fprintf(file,"Date of Birth \t\t: %s\n",students[i].bdate.c_str());
        fprintf(file,"Facebook profile link \t: %s\n",students[i].flink.c_str());
        fprintf(file,"Blood group \t\t: %s\n",students[i].bgroup.c_str());
    }

    fclose(file);
}
void SortingList()
{
    int n = students.size();

    for (int c = 0 ; c < n - 1; c++)
    {
        for (int d = 0 ; d < n - c - 1; d++)
        {
            if (students[d].id > students[d+1].id) /* For decreasing order use < */
            {
                student sw  = students[d];
                students[d]   = students[d+1];
                students[d+1] = sw;
            }
        }
    }
}

void InputData()
{
    cout<<"\n\nInsert Data \n";
    cout<<"_______________________________\n";
    student stdt;
    int len = students.size();
    int id;
    do
    {
        cout<<"Enter Student ID :"<<endl;

        cin>>id;
        bool flag = false;
        for(int i = 0; i < len; i++)
        {
            if(students[i].id == id)
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
        {
            cout<<"____________________________________\n";
            cout<<"This student ID already exist!\n"<<endl;
            //cout<<"-------------------------------------\n";
        }
        else
            break;
    }
    while(1);
    string dummy;
    getline(cin,dummy);
    string name,fname,mname,gender,email,pnumber,flink,bdate,bgroup;

    cout<<"Enter name : ";
    getline(cin,name);

    cout<<"Enter Father's name : ";
    getline(cin,fname);

    cout<<"Enter Mother's name : ";
    getline(cin,mname);

    cout<<"Enter Gender  : \n0->Male\n1->Female\n2->Others\n";
    getline(cin,gender);
    if(gender == "0")
        gender = "Male";
    else if(gender == "1")
        gender = "Female";
    else
        gender = "Others";

    cout<<"Enter Email Address : ";
    getline(cin,email);

    cout<<"Enter Phone Number : ";
    getline(cin,pnumber);

    cout<<"Enter Date of Birth : (this format -> dd.mm.yyyy)";
    getline(cin,bdate);

    string temp;
    cout<<"Enter Blood group : \n1->A+\n2->A-\n3->B+\n4->B-\n5->AB+\n6->AB-\n7->O+\n8->O-\n";
    getline(cin,temp);

    switch(atoi(temp.c_str()))
    {

    case 1:
        bgroup = "A+";
        break;
    case 2:
        bgroup = "A-";
        break;
    case 3:
        bgroup = "B+";
        break;
    case 4:
        bgroup = "B-";
        break;
    case 5:
        bgroup = "AB+";
        break;
    case 6:
        bgroup = "AB-";
        break;
    case 7:
        bgroup = "O+";
        break;
    case 8:
        bgroup = "O-";
        break;
    default :
        bgroup = "N\\A";
        break;
    }

    cout<<"Enter Facebook Link : (type only xxx part : https://www.facebook.com/xxx)";
    getline(cin,flink);

    stdt.id = id;
    stdt.name = name;
    stdt.fname = fname;
    stdt.mname = mname;
    stdt.gender = gender;
    stdt.email = email;
    stdt.pnumber = pnumber;
    stdt.bdate = bdate;
    stdt.bgroup = bgroup;
    stdt.flink = "https://www.facebook.com/"+flink;

    students.push_back(stdt);
    //sort(students.begin(),students.end());
    SortingList();
    PrintInFile();
    PrintReport();
    cout<<"__________________________________\n";
    cout<<"Your data is successfully inserted!\n";


}

void UpdateData()
{
    cout<<"\n\nUpdate Data \n";
    cout<<"_______________________________\n";
    student stdt;
    int len = students.size();
    int id;
    int idx;
    do
    {
        cout<<"Enter Student ID for update :"<<endl;

        cin>>id;
        bool flag = false;
        for(int i = 0; i < len; i++)
        {
            if(students[i].id == id)
            {
                flag = true;
                idx = i;
                break;
            }
        }
        if(flag != true)
        {
            cout<<"____________________________________\n";
            cout<<"This student ID doesn't exist!\n"<<endl;
            //cout<<"-------------------------------------\n";
            return;
        }
        else
            break;
    }
    while(1);
    string dummy;
    getline(cin,dummy);
    string name,fname,mname,gender,email,pnumber,flink,bdate,bgroup;

    cout<<"Enter name : ";
    getline(cin,name);

    cout<<"Enter Father's name : ";
    getline(cin,fname);

    cout<<"Enter Mother's name : ";
    getline(cin,mname);

    cout<<"Enter Gender  : \n0->Male\n1->Female\n2->Others\n";
    getline(cin,gender);
    if(gender == "0")
        gender = "Male";
    else if(gender == "1")
        gender = "Female";
    else
        gender = "Others";

    cout<<"Enter Email Address : ";
    getline(cin,email);

    cout<<"Enter Phone Number : ";
    getline(cin,pnumber);

    cout<<"Enter Date of Birth : (this format -> dd.mm.yyyy)";
    getline(cin,bdate);

    string temp;
    cout<<"Enter Blood group : \n1->A+\n2->A-\n3->B+\n4->B-\n5->AB+\n6->AB-\n7->O+\n8->O-\n";
    getline(cin,temp);

    switch(atoi(temp.c_str()))
    {

    case 1:
        bgroup = "A+";
        break;
    case 2:
        bgroup = "A-";
        break;
    case 3:
        bgroup = "B+";
        break;
    case 4:
        bgroup = "B-";
        break;
    case 5:
        bgroup = "AB+";
        break;
    case 6:
        bgroup = "AB-";
        break;
    case 7:
        bgroup = "O+";
        break;
    case 8:
        bgroup = "O-";
        break;
    default :
        bgroup = "N\\A";
        break;
    }

    cout<<"Enter Facebook Link : (type only xxx part : https://www.facebook.com/xxx)";
    getline(cin,flink);

    stdt.id = id;
    stdt.name = name;
    stdt.fname = fname;
    stdt.mname = mname;
    stdt.gender = gender;
    stdt.email = email;
    stdt.pnumber = pnumber;
    stdt.bdate = bdate;
    stdt.bgroup = bgroup;
    stdt.flink = "https://www.facebook.com/"+flink;

    students[idx] = stdt;
    //sort(students.begin(),students.end());
    SortingList();
    PrintInFile();
    PrintReport();
    cout<<"__________________________________\n";
    cout<<"Your data is successfully Updated!\n";
}

void DeleteData()
{

    cout<<"\n\nDelete Data \n";
    cout<<"_______________________________\n";
    student stdt;
    int len = students.size();
    int id;
    int idx;
    do
    {
        cout<<"Enter Student ID for update :"<<endl;

        cin>>id;
        bool flag = false;
        for(int i = 0; i < len; i++)
        {
            if(students[i].id == id)
            {
                flag = true;
                idx = i;
                break;
            }
        }
        if(flag != true)
        {
            cout<<"____________________________________\n";
            cout<<"This student ID doesn't exist!\n"<<endl;
            //cout<<"-------------------------------------\n";
            return;
        }
        else
            break;
    }
    while(1);

    students.erase(students.begin()+idx);
    //sort(students.begin(),students.end());
    SortingList();
    PrintInFile();
    PrintReport();
    cout<<"__________________________________\n";
    cout<<"Your data is successfully Deleted!\n";
}


int main()
{

    //CreateDatabase();
    LoadStudentInfoFromFile();

    int x;

    do
    {
        cout<<"\n_________________\n";
        cout<<"|1.Show Data\t|\n";
        cout<<"|2.Insert Data\t|\n";
        cout<<"|3.Update Data\t|\n";
        cout<<"|4.Delete Date\t|\n";
        cout<<"|5.Exit\t\t|\n";
        cout<<"-----------------\n";

        cin>>x;

        if(x == 5)
        {
            PrintReport();
            PrintInFile();
            break;
        }
        else if(x == 1)
            PrintInConsole();
        else if(x == 2)
            InputData();
        else if(x == 3)
            UpdateData();
        else if(x == 4)
            DeleteData();
        else
        {
            PrintReport();
            PrintInFile();
            break;
        }

    }
    while(1);
}
