#include "VideoGame.h"
#include <iostream>

void swap(std::vector<VideoGame>& v,int a,int b){
	VideoGame temp = v.at(a);
	v.at(a)=v.at(b);
	v.at(b)=temp;
}
int PriceSort(std::vector<VideoGame>& v, int low, int high){
	int pivot = v.at(low).getPrice();
	int up = low;
	int down = high;
	
	while(up < down){
		for(int j = up; j < high; j++){
			if(v.at(up).getPrice() > pivot){
				break;
			}
			up++;
		}
		for(int j = high; j > low; j--){
			if(v.at(down).getPrice() < pivot){
				break;
			}
			down--;
		}
		if(up<down){
			swap(v,up,down);
		}
		swap(v,low,down);
	}
}
int TitleSort(std::vector<VideoGame>& v, int low, int high){
	std::string pivot = v.at(low).getTitle();
	int up = low;
	int down = high;
	
	while(up < down){
		for(int j = up; j < high; j++){
			if(v.at(up).getTitle() > pivot){
				break;
			}
			up++;
		}
		for(int j = high; j > low; j--){
			if(v.at(down).getTitle() < pivot){
				break;
			}
			down--;
		}
		if(up<down){
			swap(v,up,down);
		}
		swap(v,low,down);
	}
}
void QuickSortPrice(std::vector<VideoGame>& v, int low, int high){
	if(low < high){
		int pivot = PriceSort(v,low,high);
		QuickSortPrice(v,low,pivot-1);
		QuickSortPrice(v,pivot+1,high);
	}
}
void QuickSortTitle(std::vector<VideoGame>& v, int low, int high){
	if(low < high){
		int pivot = TitleSort(v,low,high);
		QuickSortTitle(v,low,pivot-1);
		QuickSortTitle(v,pivot+1,high);
	}
}


void mergeTitle(std::vector<VideoGame>& v, int left, int mid, int right){
  int v1 = left;
  int v2 = mid + 1;

  std::vector<VideoGame> tempV;

	while (v1 <= mid && v2 <= right) {
		if (v[v1].getTitle() <= v[v2].getTitle()) {
			tempV.push_back(v[v1]);
			v1++;
		}
		else {
			tempV.push_back(v[v2]);
			v2++;
		}
  }

  while (v1 <= mid) {
		tempV.push_back(v[v1]);
		v1++;
	}

	while (v2 <= right) {
		tempV.push_back(v[v2]);
		v2++;
	}

	for (int i = left; i <= right; i++)
  {
    v[i] = tempV[i - left];
  }
}

void mergeSortTitle(std::vector<VideoGame>& v, int first, int end){
  if(first < end){
    int mid = (first + end) / 2;
    mergeSortTitle(v, first, mid);
    mergeSortTitle(v, mid + 1, end);
    mergeTitle(v, first, mid, end);
  }
}

void mergePrice(std::vector<VideoGame>& v, int left, int mid, int right){
  int v1 = left;
  int v2 = mid + 1;

  std::vector<VideoGame> tempV;

	while (v1 <= mid && v2 <= right) {
		if (v[v1].getPrice() <= v[v2].getPrice()) {
			tempV.push_back(v[v1]);
			v1++;
		}
		else {
			tempV.push_back(v[v2]);
			v2++;
		}
  }

  while (v1 <= mid) {
		tempV.push_back(v[v1]);
		v1++;
	}

	while (v2 <= right) {
		tempV.push_back(v[v2]);
		v2++;
	}

	for (int i = left; i <= right; i++)
  {
    v[i] = tempV[i - left];
  }
}

void mergeSortPrice(std::vector<VideoGame>& v, int first, int end){
  if(first < end){
    int mid = (first + end) / 2;
    mergeSortPrice(v, first, mid);
    mergeSortPrice(v, mid + 1, end);
    mergePrice(v, first, mid, end);
  }
}

int main(){
  return 0;
}
