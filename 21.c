// Question # 05: [Points: 04], Time: 20 minutes
// Consider: Two trains are on the same track and they are coming toward each other. The speed of the
// first train is 50 km/h and the speed of the second train is 70 km/h. A honeybee starts flying between the
// trains when the distance between two trains is 100 km. The honeybee first flies from first train to
// second train. Once it reaches the second train, it immediately flies back to the first train … and so on
// until trains collide. Calculate the total distance travelled by the honeybee. Speed of a honeybee is 80
// km/h. Distance formula is given below.
// Total distance travelled by honeybee:
// (honeybee speed * distance)/(train_1 speed + train_2 speed)
// Your task is to solve the problem recursively (direct or indirect).


#include <stdio.h>

float calculatedistance(int train_1speed , int train_2speed , int honeybee_speed , int distance ){
    if (distance <= 0)
    {
        printf("Train Collided");
        return 0;
    }

    // Time for honeybee to reach the opposite train
    float time = distance / (train_1speed + train_2speed);

    // Distance honeybee travels in this leg
    float distanceTravelled = honeybee_speed * time;

    // Remaining distance between trains
    float newDistance = distance - (train_1speed + train_2speed) * time;



    return distanceTravelled + calculatedistance(train_1speed, train_2speed, honeybee_speed, newDistance);
}

int main(){
    int train_1speed = 50 ;
    int train_2speed = 70 ;
    int honeybee_speed = 80 ;
    int distance = 100 ;
    float totaldistance ;


    totaldistance = calculatedistance(train_1speed , train_2speed , honeybee_speed , distance);

    printf("Total distance travelled by honeybee: %.2f km\n", totaldistance);

    return 0 ;
}