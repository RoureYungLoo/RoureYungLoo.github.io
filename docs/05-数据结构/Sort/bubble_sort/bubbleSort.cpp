#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;
using std::swap;

vector<int> nums({9,6,7,3,2,5,1,11}); 

void bubleSort(vector<int> &nums);
void printer(vector<int> items);


int main(){
    bubleSort(nums);
    printer(nums);
    return 0;
}

void bubleSort(vector<int> &nums){
    int n=nums.size();  //数组长度
    int round=n-1;  //总共需要比较的轮次，2个数1轮，3个数2轮，n个数(n-1)轮
    for (size_t i = 0; i < round; i++) { //比较round轮，i=[0,1,2,round-1]
        for (size_t j = 0; j < round-i; j++) {    //第i轮比较(round-i)次
            if(nums[j]>nums[j+1])
                swap(nums[j],nums[j+1]);
        }
    }
}

void printer(vector<int> items){
    if (items.size()){
        for (auto item:items){
            cout<<item<<" ";
        }
        cout<<endl;
    }else{
        cout<<"数组长度为0"<<endl;         
    }
  
}


