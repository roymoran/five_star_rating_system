/* ----------------------------------------------------------------
 * Weighted Average Rating System
 *
 * Anautomy, Fall 2015
 * Author: Roy Moran
 *
 * To-do: The following program implements a weighted average rating system
 *        similar to a system used on yelp.com and other websites
 * -----------------------------------------------------------------
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

float basic_rating_system(void);
float advanced_rating_system(void);
void rating_collector(int, int, int, int, int);
float rating_converter(float);

int main(void)
{
    char y = 'y';
    do{
        float overall_rating;
        setbuf(stdout, NULL); //for debugging purposes
        overall_rating = basic_rating_system();
    
        printf("\n\nOver all rating: %.1f\n", overall_rating);
        printf("--------------------------------");
        printf("\n\nEnter new ratings? [y/n]: ");
        scanf("%s", &y);
        printf("\n");

    } while (y == 'y');
    
    printf("Now exiting...");
    return 0;
}
//Function that collects the total ratings through stdin
void rating_collector(int *total_5_star, int *total_4_star, int *total_3_star, int *total_2_star, int *total_1_star)
{
    std::cout << "Total 5 star ratings: ";
    std::cin >> *total_5_star;
    std::cout << "Total 4 star ratings: ";
    std::cin >> *total_4_star;
    std::cout << "Total 3 star ratings: ";
    std::cin >> *total_3_star;
    std::cout << "Total 2 star ratings: ";
    std::cin >> *total_2_star;
    std::cout << "Total 1 star ratings: ";
    std::cin >> *total_1_star;
}

//Rating converter takes the rating and rounds it up or down to the
//nearest integer or half integer
float rating_converter(float rating){
    
    if (rating >= 4.75)
    {
        rating = 5;
    }
    else if (rating >= 4.25 && rating <= 4.74)
    {
        rating = 4.5;
    }
    else if (rating >= 3.75 && rating <= 4.24)
    {
        rating = 4;
    }
    else if (rating >= 3.25 && rating <= 3.74)
    {
        rating = 3.5;
    }
    else if (rating >= 2.75 && rating <= 3.24)
    {
        rating = 3;
    }
    else if (rating >= 2.25 && rating <= 2.74)
    {
        rating = 2.5;
    }
    else if (rating >= 1.75 && rating <= 2.24)
    {
        rating = 2;
    }
    else if (rating >= 1.25 && rating <= 1.74)
    {
        rating = 1.5;
    }
    else if (rating >= 0.75 && rating <= 1.24)
    {
        rating = 1;
    }
    else if (rating >= 0.25 && rating <= 0.74)
    {
        rating = 0.5;
    }
    else
    {
        rating = 0; //no ratings or low rating
    }
    
    return rating;
}
//The basic rating system will take the total number of 5 star, 4 star, 3 star, 2 star, and 1 star ratings, add them then take the weighted average using the total number of ratings. The final rating will be of the form 5, 4.5, 4, 3.5, etc.
//Implemented by sites like Yelp (Amazon uses machine learning algorithm)
float basic_rating_system(void)
{
    int total_5_star,total_4_star,total_3_star,total_2_star, total_1_star;
    float total_ratings;
    float overall_rating;
    rating_collector(&total_5_star, &total_4_star, &total_3_star, &total_2_star, &total_1_star);
    
    // add up all ratings to get total number of ratings
    total_ratings = total_5_star + total_4_star + total_3_star + total_2_star + total_1_star;
    
    //average all ratings
    overall_rating = ((5 * total_5_star) + (4 * total_4_star) + (3 * total_3_star) + (2 * total_2_star) + (total_1_star))/total_ratings;
    printf("\n\nShop number of total ratings: %d\n", (int)total_ratings);
    printf("%f", overall_rating);
    
    overall_rating = rating_converter(overall_rating);
    
    return overall_rating;
}

float advanced_rating_system(void)
{
    int total_5_star,total_4_star,total_3_star,total_2_star, total_1_star;
    //float total_ratings;
    float overall_rating;
    rating_collector(&total_5_star, &total_4_star, &total_3_star, &total_2_star, &total_1_star);
    
    //Advanced rating system could be implemented in various ways taking into account various metrics of what you are rating
    //Metric could include age of rating, helpfulness of ratings to other users, or any metric to wish to have an impact on the rating
    //advanced_rating_system currently not implemented
    return overall_rating;
}