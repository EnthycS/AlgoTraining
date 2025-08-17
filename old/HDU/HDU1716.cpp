#include<bits/stdc++.h>
using namespace std;


int main(){
	
	int nums[4];
    bool first_case = true;
    
    while(cin >> nums[0] >> nums[1] >> nums[2] >> nums[3]){
    	if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0 && nums[3] == 0) {
            break;
        }
        
        if(!first_case){
        	cout<<endl;
		}else{
			first_case = false;
		}
		
		sort(nums,nums+4);
		vector<int> result;
		
		do{
			if(nums[0] == 0){
				continue;
			}
			
			int num = nums[0]*1000+nums[1]*100+nums[2]*10+nums[3];
			result.push_back(num);
		}while(next_permutation(nums,nums+4));
		
		if(!result.empty()){
			int current_thousand = result[0] / 1000;
            vector<int> current_line;
            current_line.push_back(result[0]);
            
            for (size_t i = 1; i < result.size(); ++i){
            	int thousand = result[i]/1000;
            	if(thousand == current_thousand){
            		current_line.push_back(result[i]);
				}else{
					for (size_t j = 0; j < current_line.size(); ++j) {
                        if (j != 0) {
                            cout << " ";
                        }
                        cout << current_line[j];
                    }
                    
                    cout<<endl;
                    
                    current_line.clear();
                    current_line.push_back(result[i]);
                    current_thousand = thousand;
				}
				
				
			}
			
			// 输出最后一行
            for (size_t j = 0; j < current_line.size(); ++j) {
                if (j != 0) {
                    cout << " ";
                }
                cout << current_line[j];
            }
            cout << endl;
		}
	}
	
	
	return 0;
} 
