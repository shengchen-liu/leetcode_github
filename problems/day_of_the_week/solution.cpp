class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int num=((year-1971));
        long date= (num/4)*1461;
        int arr[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        num=num%4;
        if(num==1)
        {
            arr[1]=29;
            date+=365;
        }
        else if(num==2)
            date+=366+365;
        else if(num==3)
            date+=365+365+366;
        for(int i=0;i<month-1;i++)
        {
            date+=arr[i];
        }
        date+=day;
        vector<string> ret(7);
        ret[0]="Thursday";
        ret[1]="Friday";
        ret[2]="Saturday";
        ret[3]="Sunday";
        ret[4]="Monday";
        ret[5]="Tuesday";
        ret[6]="Wednesday";
        cout<<num;
        return ret[date%7];
    }
};