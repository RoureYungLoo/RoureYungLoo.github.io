#include <iostream>
#include<vector>

using namespace std;
vector<int> nums({8,5,2,6,9,3,1,4,0,7});
void selectSort(vector<int> &nums);
void printer(vector<int> items);

int main(int argc, char const *argv[]) {
    selectSort(nums);
    printer(nums);
    return 0;
}
void selectSort(vector<int> &nums){
    int n=nums.size();  //假设n=10
    int round=n-1; //需要选择9轮，n个元素需要(n-1)轮选择，第n轮选择只有最后一个元素
    int minIndex=-1;    
    for (size_t i = 0; i < round; i++) {//i=0,1,2,3,4,5,6,7,8
        minIndex=i;
        for (size_t j = i+1; j < n; j++) { //第i轮选择下标范围[i+1,n-1]
            if(nums[minIndex]>nums[j]) //记录较小值的index
                minIndex=j; //更新minIndex
        }
        swap(nums[i],nums[minIndex]);//选择最小的交换
    }
}
void printer(vector<int> items){
    if(items.size()){
        for(auto item:items){
            cout<<item<<" ";
        }
        cout<<endl;
    }else{
        cout<<"数组长度为0";
    }
}