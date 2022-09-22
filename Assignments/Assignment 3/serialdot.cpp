#include <bits/stdc++.h>
using namespace std;

int dot_product(vector<int> &v1, vector<int> &v2){
    int product = 0;
    for(int i=0;i<v1.size();i++)
        product += v1[i] * v2[i];
    return product;
}
int main() {
	clock_t start, finish;
    start = clock();
    vector<int> V1 ;
    vector<int> V2;
    int length1,length2,input,product = 0;
    cout<<"Enter size of first vector:";
    cin >> length1;
    cout<<"Enter size of second vector:";
    cin >> length2;
    cout << "Enter elements of the first vector:";
    for(int i=0;i<length1;i++){
        cin>>input;
        V1.push_back(input);
    }
    cout << "Enter elements of the second vector:";
    for(int i=0;i<length2;i++){
        cin>>input;
        V2.push_back(input);
    }
    cout << "Dot product : " << dot_product(V1,V2);
    finish = clock();
    double tt = (double)(finish-start)/CLOCKS_PER_SEC;
  	printf("\nExec time is: %lf",tt);
    return 0;
}

