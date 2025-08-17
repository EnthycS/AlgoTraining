#include<bits/stdc++.h>
using namespace std;

struct interval{
	double start;
	double end;
};
//第一个矩形的坐标轴投影 
struct interval intervalX1;
struct interval intervalY1;

//第二个矩形的坐标轴投影 
struct interval intervalX2;
struct interval intervalY2;

void init(double x1, double y1,double x2,double y2,double x3,double y3,double x4,double y4 ){ //创建时选择小的作为起点 
		if(x1 < x2){
			intervalX1.start = x1;
			intervalX1.end = x2;
		}else{
			intervalX1.start = x2;
			intervalX1.end = x1;
		}
		
		if(x3 < x4){
			intervalX2.start = x3;
			intervalX2.end = x4;
		}else{
			intervalX2.start = x4;
			intervalX2.end = x3;
		}
		
		if(y1 < y2){
			intervalY1.start = y1;
			intervalY1.end = y2;
		}else{
			intervalY1.start = y2;
			intervalY1.end = y1;
		}
		
		if(y3 < y4){
			intervalY2.start = y3;
			intervalY2.end = y4;
		}else{
			intervalY2.start = y4;
			intervalY2.end = y3;
		}
		
		//cout<<"IntervalX1 :"<<"Start :"<<intervalX1.start<<" End: "<<intervalX1.end<<endl;
		//cout<<"IntervalX2 :"<<"Start :"<<intervalX2.start<<" End: "<<intervalX2.end<<endl;
		//cout<<"IntervalY1 :"<<"Start :"<<intervalY1.start<<" End: "<<intervalY1.end<<endl;
		//cout<<"IntervalY2 :"<<"Start :"<<intervalY2.start<<" End: "<<intervalY2.end<<endl;
}

struct interval intersect1;
struct interval intersect2;

//bool isIntersect(struct interval i1 , struct interval i2 ){
//	if( (i1.start < i2.start) && (i1.end > i2.start)  ){
//		
//		return true;
//		
//	}else if((i2.start < i1.start) && (i2.end > i1.start)){
//		
//		return true;
//	}else{
//		return false;
//	}
//	
//}
bool isIntersect(struct interval i1, struct interval i2) {
    return i1.start < i2.end && i2.start < i1.end;
}

double getIntersect(struct interval i1 , struct interval i2 ){//假设传入区间i1更靠左 
	double x1 = i1.start;
	double x2 = i1.end;
	
	double x3 = i2.start;
	double x4 = i2.end;
	
	double len1 = x2 - x1;
	double len2 = x4 - x3;
	
	double res = 0.0;
	
	if(x2 < x4){
		res = x2 - x3;
	}else {
		res = x4 - x3;
	}
	return res;
	
}


int main(){
	double x1,y1,x2,y2,x3,y3,x4,y4;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4){
		
		init(x1,y1,x2,y2,x3,y3,x4,y4);
		if( !( isIntersect(intervalX1 , intervalX2) && isIntersect(intervalY1,intervalY2) ) ){
			cout<<"0.00"<<endl;
		}else{
			double Width;
			double Height;
			if(intervalX1.start < intervalX2.start){
				Width = getIntersect(intervalX1,intervalX2);
			}else{
				Width = getIntersect(intervalX2,intervalX1);
			}
			
			if(intervalY1.start < intervalY2.start){
				Height = getIntersect(intervalY1,intervalY2);
			}else{
				Height = getIntersect(intervalY2,intervalY1);
			}
			
			double res = Width * Height;
			//cout<<"width is :"<<Width<<" Height is :"<<Height<<endl;
			printf("%.2lf\n",res);
		}
		
	}
	return 0;
}
