#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include "VideoGame.h"
using namespace std::chrono;

void printMenu();
void printGames(std::vector<VideoGame>& games);
void dataFromCSV(const std::string& filepath, std::vector<VideoGame>& games);
void minPlayerGames(std::vector<VideoGame>& games, int min_players);
void genreGames(std::vector<VideoGame>& games, int genre_choice);
void consoleGames(std::vector<VideoGame>& games, int console_choice);
void mergeTitle(std::vector<VideoGame>& v, int left, int mid, int right);
void mergeSortTitle(std::vector<VideoGame>& v, int first, int end);
void mergePrice(std::vector<VideoGame>& v, int left, int mid, int right);
void mergeSortPrice(std::vector<VideoGame>& v, int first, int end);

int main()
{
    int option = 0;
    std::vector<VideoGame> games;
    dataFromCSV("video_games.csv", games);
    printMenu();
    std::cin >> option;
    while(option != 4)
    {
        if(option == 1)
        {
            int sort_choice = 0;
            do
            {
                std::cout << "Please choose an option to sort the games: " << std::endl;
                std::cout << "1. Used Price\n2. Review\n3. Rating\n4. Average Completion Time\n5. Back" << std::endl;
                std::cin >> sort_choice;

                std::vector<VideoGame> tempVect;
                for (int i=0; i<games.size(); i++) 
                    tempVect.push_back(games[i]); 

                if(sort_choice == 1)
                {
                    auto start = high_resolution_clock::now();

                    mergeSortPrice(tempVect, 0, tempVect.size()-1);

                    auto stop = high_resolution_clock::now();
                    auto m_duration = duration_cast<microseconds>(stop - start);
                    start = high_resolution_clock::now();
                    // Call quick sort function for price
                    stop = high_resolution_clock::now();
                    auto q_duration = duration_cast<microseconds>(stop - start);
                    // Print games
                    std::cout << "Time taken for merge sort: " << m_duration.count() << " microseconds" << std::endl;
                    std::cout << "Time taken for quick sort: " << q_duration.count() << " microseconds" << std::endl;
                }
                else if(sort_choice == 2)
                {
                    auto start = high_resolution_clock::now();
                    
                    mergeSortReview(tempVect, 0, tempVect.size()-1);

                    auto stop = high_resolution_clock::now();
                    auto m_duration = duration_cast<microseconds>(stop - start);
                    start = high_resolution_clock::now();
                    // Call quick sort function for review
                    stop = high_resolution_clock::now();
                    auto q_duration = duration_cast<microseconds>(stop - start);
                    // Print games
                    std::cout << "Time taken for merge sort: " << m_duration.count() << " microseconds" << std::endl;
                    std::cout << "Time taken for quick sort: " << q_duration.count() << " microseconds" << std::endl;
                }
                else if(sort_choice == 3)
                {
                    auto start = high_resolution_clock::now();
                    
                    mergeSortRating(tempVect, 0, tempVect.size()-1);

                    auto stop = high_resolution_clock::now();
                    auto m_duration = duration_cast<microseconds>(stop - start);
                    start = high_resolution_clock::now();
                    // Call quick sort function for rating
                    stop = high_resolution_clock::now();
                    auto q_duration = duration_cast<microseconds>(stop - start);
                    // Print games
                    std::cout << "Time taken for merge sort: " << m_duration.count() << " microseconds" << std::endl;
                    std::cout << "Time taken for quick sort: " << q_duration.count() << " microseconds" << std::endl;
                }
                else if(sort_choice == 4)
                {
                    auto start = high_resolution_clock::now();
                    
                    mergeSortCompletion(tempVect, 0, tempVect.size()-1);

                    auto stop = high_resolution_clock::now();
                    auto m_duration = duration_cast<microseconds>(stop - start);
                    start = high_resolution_clock::now();
                    // Call quick sort function for completion
                    stop = high_resolution_clock::now();
                    auto q_duration = duration_cast<microseconds>(stop - start);
                    // Print games
                    std::cout << "Time taken for merge sort: " << m_duration.count() << " microseconds" << std::endl;
                    std::cout << "Time taken for quick sort: " << q_duration.count() << " microseconds" << std::endl;
                }
                else if(sort_choice != 5)
                    std::cout << "Please choose a valid option." << std::endl;
            } while (sort_choice > 5 || sort_choice < 1);
        }
        else if(option == 2)
        {
            int category_choice = 0;
            do
            {
                std::cout << "Please choose an option to filter the games: " << std::endl;
                std::cout << "1. Minimum Number of Players\n2. Genre\n3. Console\n4. Back" << std::endl;
                std::cin >> category_choice;
                if(category_choice == 1)
                {
                    int players = 0;
                    std::cout << "What is the minimum number of players you would like for this game? ";
                    std::cin >> players;
                    if(players > 0 && players < 9)
                    {
                        minPlayerGames(games, players);
                        printGames(games);
                    }
                    else
                    {
                        std::cout << "Sorry! No games are available that support that many players." << std::endl;
                    }
                }
                else if(category_choice == 2)
                {
                    int genre_choice = 0;
                    do
                    {
                        std::cout << "Choose what genre of games you would like to play: " << std::endl;
                        std::cout << "1. Action\n2. Adventure\n3. Driving/Racing\n4. Role-Play (RPG)\n5. Simulation\n6. Sports\n7. Strategy\n8. Back" << std::endl;
                        std::cin >> genre_choice;
                        if(genre_choice > 0 && genre_choice < 8)
                        {
                            genreGames(games, genre_choice);
                            printGames(games);
                        }
                        else if(genre_choice < 1 || genre_choice > 8)
                            std::cout << "Please choose a valid option." << std::endl;
                        else
                            category_choice = 0;
                    } while(genre_choice < 1 || genre_choice > 8);
                }
                else if(category_choice == 3)
                {
                    int console_choice = 0;
                    do
                    {
                        std::cout << "Choose what console you would prefer to play: " << std::endl;
                        std::cout << "1. Nintendo DS\n2. Nintendo Wii\n3. PlayStation 3\n4. Sony PSP\n5. Xbox 360\n6. Back" << std::endl;
                        std::cin >> console_choice;
                        if(console_choice > 0 && console_choice < 6)
                        {
                            consoleGames(games, console_choice);
                            printGames(games);
                        }
                        else if(console_choice < 1 || console_choice > 6)
                            std::cout << "Please choose a valid option." << std::endl;
                        else
                            category_choice = 0;
                    } while(console_choice < 1 || console_choice > 6);
                }
                else if(category_choice != 4)
                    std::cout << "Please choose a valid option." << std::endl;
            } while (category_choice > 4 || category_choice < 1);
        }
        else if(option == 3)
        {
            dataFromCSV("video_games.csv", games);
        }
        else
            std::cout << "Please choose a valid option." << std::endl;
        printMenu();
        std::cin >> option;
    }
    return 0;
}

void printMenu()
{
    std::cout << "Choose an option: " << std::endl;
    std::cout << "1. Sort Games\n2. Filter Games\n3. Reset Games\n4. Quit" << std::endl;
}

void printGames(std::vector<VideoGame>& games)
{
    for(int i = 0; i < games.size(); i++)
    {
        std::cout << i + 1 << ". " << games[i].getTitle() <<std::endl;
        std::cout << "Release Year: " << games[i].getYear() << " Genres: " << games[i].getGenres() << " Console: " << games[i].getConsole()
        << " Used Price: $" << games[i].getPrice() << " Review Score: " << games[i].getReview() << " Rating: " << games[i].getRating()
        << " Average Completion Time: " << games[i].getCompletion() << " Maximum Players: " << games[i].getPlayers() << std::endl;
    }
}

void dataFromCSV(const std::string& filepath, std::vector<VideoGame>& games)
{
    std::ifstream inFile(filepath);
    if(inFile.is_open())
    {
        std::string file_line;
        std::getline(inFile, file_line);
        while(std::getline(inFile, file_line))
        {
            std::string temp;
            std::string title;
            std::string temp_players;
            int players;
            std::string genres;
            std::string temp_review;
            int review_score;
            std::string temp_price;
            float price;
            std::string console;
            std::string rating;
            std::string temp_year;
            int year;
            std::string temp_completion;
            float completion;
            std::istringstream stream(file_line);
            std::getline(stream, title, '"');
            std::getline(stream, title, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp_players, '"');
            std::getline(stream, temp_players, '"');
            players = std::stoi(temp_players);
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, genres, '"');
            std::getline(stream, genres, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp_review, '"');
            std::getline(stream, temp_review, '"');
            review_score = std::stoi(temp_review);
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp_price, '"');
            std::getline(stream, temp_price, '"');
            price = std::stof(temp_price);
            std::getline(stream, console, '"');
            std::getline(stream, console, '"');
            std::getline(stream, rating, '"');
            std::getline(stream, rating, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp_year, '"');
            std::getline(stream, temp_year, '"');
            year = std::stoi(temp_year);
            std::getline(stream, temp_completion, '"');
            std::getline(stream, temp_completion, '"');
            completion = std::stof(temp_completion);
            VideoGame v(title, genres, players, review_score, price, console, rating, year, completion);
            games.push_back(v);
        }
    }
}

void minPlayerGames(std::vector<VideoGame>& games, int min_players)
{
    for(int i = 0; i < games.size(); i++)
    {
        if(games[i].getPlayers() < min_players)
        {
            games.erase(games.begin() + i);
            i--;
        }
    }
}

void genreGames(std::vector<VideoGame>& games, int genre_choice)
{
    std::string genre;
    if(genre_choice == 1)
        genre = "Action";
    else if(genre_choice == 2)
        genre = "Adventure";
    else if(genre_choice == 3)
        genre = "Driving";
    else if(genre_choice == 4)
        genre = "RPG";
    else if(genre_choice == 5)
        genre = "Simulation";
    else if(genre_choice == 6)
        genre = "Sports";
    else if(genre_choice == 7)
        genre = "Strategy";
    for(int i = 0; i < games.size(); i++)
    {
        if(games[i].getGenres().find(genre) == std::string::npos)
        {
            games.erase(games.begin() + i);
            i--;
        }
    }
}

void consoleGames(std::vector<VideoGame>& games, int console_choice)
{
    std::string console;
    if(console_choice == 1)
        console = "DS";
    else if(console_choice == 2)
        console = "Wii";
    else if(console_choice == 3)
        console = "PlayStation";
    else if(console_choice == 4)
        console = "PSP";
    else if(console_choice == 5)
        console = "360";
    for(int i = 0; i < games.size(); i++)
    {
        if(games[i].getConsole().find(console) == std::string::npos)
        {
            games.erase(games.begin() + i);
            i--;
        }
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

void mergeCompletion(std::vector<VideoGame>& v, int left, int mid, int right){
  int v1 = left;
  int v2 = mid + 1;

  std::vector<VideoGame> tempV;

	while (v1 <= mid && v2 <= right) {
		if (v[v1].getCompletion() <= v[v2].getCompletion()) {
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

void mergeSortCompletion(std::vector<VideoGame>& v, int first, int end){
  if(first < end){
    int mid = (first + end) / 2;
    mergeSortCompletion(v, first, mid);
    mergeSortCompletion(v, mid + 1, end);
    mergeCompletion(v, first, mid, end);
  }
}

