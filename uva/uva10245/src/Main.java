public class Main {
	  
	double dist(int p1, int p2) {
	  return hypot(x[p1] - x[p2], y[p1] - y[p2]); }
	  
	bool x_comparator (point a,point b) { return (a.x < b.x); }

	vector<point> arr;

	double minimise(int start, int end){

	       if (start+1 == end)
	           return dist(arr[start],arr[end]);
	       
	       if (start >= end)
	          return 9999999.0;
	          
	       int mid = (end-start)/2;
	       double left = minimise(start,mid);
	       double right = minimise(mid+1,end);
	       double ans = min(left,right);

	       for (int i = start; i < mid+1; i++)
	           for (int j = mid+1; j < end+1; j++)
	               ans = min(ans,dist(arr[i],arr[j]));
	           
	       return ans;
	}


	int main(void){
	    int count;
	    while(true){
	        scanf("%d",&count);
	        if (count == 0)
	           break;
	        arr.clear();
	        for (int i = 0; i < count; i++){
	            double x,y;
	            scanf("%lf %lf",&x,&y);
	            arr.push_back(point(x,y));
	        }
	        std:sort(arr.begin(),arr.end(),x_comparator);
	        
	        double mindist = 9999999.0;
	        mindist = min(mindist,minimise(0,arr.size()-1));
	        
	        if (mindist < 10000.0)
	            printf("%.4lf\n",mindist);
	        else
	            printf("INFINITY\n");
	    }
	    
	    return 0;
	}

}
