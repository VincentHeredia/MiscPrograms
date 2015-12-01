//==========================================================================
//Author: Vincent Heredia
//Date: 4/10/2015
//Course: cs433
//Summary: This program aims to experiment with the pthreads and semaphore library
//Assumptions: The program is executed with parameters
//Special Instructions: To execute this program type,
//                     assign4run <time> <producer count> <consumer count>
//                     Time is how long the main thread sleeps in seconds
//                     Producer count is how many producer threads you want
//                     Consumer count is how many consumer threads you want
//==========================================================================



#include <iostream>//for input and output
#include <pthread.h>//for multithreading
//#include <stdio.h>//for c outputs
#include <stdlib.h>//for atoi function
#include "buffer.h"//for definitions
#include <semaphore.h>//for semaphore functions
using namespace std;


#define MAX_SLEEP 4 //max sleep time for threads


buffer_item buffer[BUFFER_SIZE];//buffer that holds the produced items
int front = 0;//front of the buffer
int back = 0;//back of the buffer

sem_t mutex;//semaphore for protecting shared values
sem_t full;//semaphore
sem_t empty;//semaphore


//Purpose: Prints the items in the buffer
void printBuffer(){
  int i = back;//start from back
  

  cout << "Buffer: [ ";
  while(i != front){//print until at front (front will be empty)
    cout << buffer[i] << " "; 
    i = (i + 1)%BUFFER_SIZE;
  }
  cout << "]"  << endl;
  return;
}

//Purpose: Inserts an item into the buffer
//Parameters: the item to be inserted
//Returns: 0 if succesful, -1 an error occured (buffer is full)
int insert_item(buffer_item item){

  if((front+1) == back){
    return -1;//indicating an error condition
  }
  else{
    buffer[front] = item;//insert
    front = (front+1)%BUFFER_SIZE;//move forward
    return 0;//if successful
  }
}


//Purpose: Removes an item from the buffer
//Parameters: The variable that will recieve the item
//Returns: 0 if successful, -1 if an error occured
int remove_item(buffer_item *item){

  if(back == front){//empty
    return -1;//indicating an error condition
  }
  else{
    *item = buffer[back];//take item out of back
    back = (back+1)%BUFFER_SIZE;//move forward
    return 0;//if successful
  }
}


//Purpose: Producer thread function
//Parameters: This recieves the argv[1] of the main program
//            which indicates how long the main thread will
//            be sleeping.
void * producer(void *param){
  
  buffer_item item;//the item to be inserted
  int sleepy = 0;//indicates how long the thread will sleep

  
  while(true){
    //sleep for a random period of time (between 0 and argv[1])
    sleepy = rand()% MAX_SLEEP;//atoi((char *)param);
    
    sleep(sleepy);
    //cout << "Slept for: " << sleepy << endl;
    
    item = rand()%20;//for reasonable numbers
   
    //cout << "Item: " << item << " Inserting..." << endl;
    sem_wait(&empty);//wait
    sem_wait(&mutex);//wait

    //attempt to produce
    if (insert_item(item)){//insert into buffer
      cout << "Buffer Full" << endl;
    }
    else{
      cout << "producer produced " << item << endl;
    }
    cout << endl;
    printBuffer();//print
    cout << endl;
    
    sem_post(&mutex);//signal
    sem_post(&full);//signal
  }//end of while
  
}


//Purpose: Consumer thread function
//Parameter: This recieves the argv[1] of the main program
//            which indicates how long the main thread will
//            be sleeping. 
void * consumer(void *param){
  
  buffer_item item;
  int sleepy = 0;
  
  while (true){
    //sleep for a random period of time (between 0 and argv[1])
    sleepy = rand()% MAX_SLEEP;//atoi((char *)param);
    
    sleep(sleepy);
    //cout << "Slept for: " << sleepy << endl;
    
    //cout << "Looking for item..." << endl;
    
    sem_wait(&full);//wait
    sem_wait(&mutex);//wait
    
    //attempt to consume
    if (remove_item(&item)){//remove an item from the buffer
      cout << "report error condition" << endl;
    }
    else{
      cout << "consumer consumed " << item << endl;
    }
    cout << endl;
    printBuffer();//print
    cout << endl;
    
    sem_post(&mutex);//signal
    sem_post(&empty);//singal
    
  }//end of while
  
}



//Purpose: Main function
//Parameters: argument count, arguments
//Returns: integer indicating success
int main(int argc, char *argv[]){
  //1. get command line arguments argv[1..3]
  
  srand(time(0));//seed random
  
  //create threads
  pthread_t producer_threads[atoi(argv[2])];
  pthread_t consumer_threads[atoi(argv[3])];


  
  //2. initialize buffer ???
  

  //2.5. initialize semaphores
  sem_init(&mutex,0,1);
  sem_init(&full,0,0);
  sem_init(&empty,0,(BUFFER_SIZE-1));
  
  
    //3. create producer threads
  for(int i = 0; i < atoi(argv[2]); i++){
    pthread_create(&producer_threads[i], NULL, producer, argv[1]);
  }
  //4. create consumer threads
  for(int i = 0; i < atoi(argv[3]); i++){
    pthread_create(&consumer_threads[i], NULL, consumer, argv[1]);
  }


  //5. sleep
  cout << "Main Thread Sleeping..." << endl;
  sleep(atoi(argv[1]));
  cout << "Main Thread Awake!" << endl;


  //6. exit
  for (int i = 0; atoi(argv[2]) < i; i++){
    pthread_join(producer_threads[i],NULL);
  }
  
  for (int i = 0; atoi(argv[2]) < i; i++){
    pthread_join(consumer_threads[i],NULL);
  }
  
  
  return 1;
  
}
