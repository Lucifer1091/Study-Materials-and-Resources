class Date{
 private:
 int *DateData; //day/month/year
 public:
 // default constructor
 Date() {
 DateData= new int[3];
 *(DateData+0)=0;
 *(DateData+1)=0;
 *(DateData+2)=0; }
 Date(const int a[]) {
 	
	 ///
	 
	 }
 Date(const Date & rhs) {

///

 }
 ~ Date() {


//
}
}; // class end
int main(){
Date D1, D2;
int a[3]= {10, 10, 1997};
cout << D1.getDay() << D1.getMonth()
<< D1.getYear() << endl;
Date D3(a);
cout << D3.getDay() << D3.getMonth()
<< D3.getYear() << endl;
return 0;

}
