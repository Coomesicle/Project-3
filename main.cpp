#include "VideoGame.h"

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

void mergeReview(std::vector<VideoGame>& v, int left, int mid, int right){
  int v1 = left;
  int v2 = mid + 1;

  std::vector<VideoGame> tempV;

	while (v1 <= mid && v2 <= right) {
		if (v[v1].getReview() <= v[v2].getReview()) {
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

void mergeSortReview(std::vector<VideoGame>& v, int first, int end){
  if(first < end){
    int mid = (first + end) / 2;
    mergeSortReview(v, first, mid);
    mergeSortReview(v, mid + 1, end);
    mergeReview(v, first, mid, end);
  }
}

void mergeRating(std::vector<VideoGame>& v, int left, int mid, int right){
  int v1 = left;
  int v2 = mid + 1;

  std::vector<VideoGame> tempV;

	while (v1 <= mid && v2 <= right) {
		if (v[v1].getRating() <= v[v2].getRating()) {
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

void mergeSortRating(std::vector<VideoGame>& v, int first, int end){
  if(first < end){
    int mid = (first + end) / 2;
    mergeSortRating(v, first, mid);
    mergeSortRating(v, mid + 1, end);
    mergeRating(v, first, mid, end);
  }
}

int main(){
  return 0;
}
