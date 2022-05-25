#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXIMUM_LINES 300
#define MAXIMUM_COMPONENTS 300
#define MAXIMUM_TIME 3600
#include "library.h"
// !!!!  TAKEN THE REFERENCE FROM NOTES (LECTURE 9)  !!!!! //
int main(int argc, char *argv[])
{
    FILE * input_fp;
    /* CHECKING ARGUMENT */
    if ( argc > 1 ) {
        /* if the file does not exists or is not readable, the program prints out an error message to this effect.*/
        if ( ( input_fp = fopen ( argv[ 1 ] , "r" ) ) == NULL ) {
            printf ( "It does not exist or cannot be opened for reading \n");
            return 1;
        } else {
            //read function
            READ_SONGS_FROM_FILE ( input_fp , STORED_RESULTS );
            //closing the file
            fclose ( input_fp );
        }
    } else {
        //when no file opens,we have to try the default file artiste+songs.txt//
        if ( ( input_fp = fopen ( "C:\\Users\\ishik\\CLionProjects\\SOFTWARE(1)\\artistes+songs.txt" , "r" ) ) ==
             0 )//if file is not found in directory
        {
            printf ( "No file found.!!!!!\n");
            /* When artiste+songs.txt is not there.Ask the user to enter from keyboard*/
            printf ( "Please enter the artists and their songs from the keyboard in the below format: \n" );
            /* Format for entering artists and their songs from the keyboard */
            /*STRICT FORMAT (From notes) */
            printf (
                    "Artiste name\n"
                    "Song title***Song duration(mm:ss)\n"
                    "Song title***Song duration(mm:ss)\n"
                    "...\n"
                    "Song title***Song duration(mm:ss)\n"
                    "<blank line>\n"
                    "Artiste name\n"
                    "Song title***Song duration(mm:ss)\n"
                    "Song title***Song duration(mm:ss)\n"
                    "...\n"
                    "Song title***Song duration(mm:ss)\n"
                    "<blank line>"
                    "Press enter and type DONE once you are finished entering the input.\n" );
            ENTERED_BY_USER ( STORED_RESULTS ); //USER INPUT FUNCTION //
        } else {
            READ_SONGS_FROM_FILE ( input_fp , STORED_RESULTS ); //Read function//
            fclose ( input_fp ); //CLOSING THE FILE
        }
    }

    srand ( time ( NULL ) ); /* Random generator function */
    /* INITIALISING THE FUNCTIONS */
    SORT_RESULTS ( STORED_RESULTS ); //FUNCTION FOR SORTING //
    PRINT_SORT_RESULTS ( STORED_RESULTS ); //FUNCTION FOR PRINTING SORTED LIST //
    RANDOM_RESULTS ( STORED_RESULTS ); //FUNCTION FOR RANDOM SONG SELECTION //
    PRINT_RANDOM_RESULTS ( STORED_RESULTS ); //FUNCTION FOR PRINTING RANDOM SONG SELECTION //
    return 0;
}

/* Taking the reference from:::::
 * https://www.educative.io/edpresso/how-to-copy-a-string-using-strcpy-function-in-c
 * https://www.techbaz.org/Course/C_string.php
 * */
/* Function for the input entered by the user */
void ENTERED_BY_USER ( char (* STORED_RESULTS)[300] ) {
    number_of_songs = 0;
    while ( i < MAXIMUM_COMPONENTS ) {
        /* ARTIST INFO BY THE USER */
        fgets ( ARTIST[ j ] , MAXIMUM_COMPONENTS , stdin );
        if ( ARTIST[ j ][ strlen ( ARTIST[ j ] ) - 1 ] == '\n' ) {
            ARTIST[ j ][ strlen ( ARTIST[ j ] ) - 1 ] = '\0';
        }
        /* when user wants to stop entering the input */
        if ( strcmp ( ARTIST[ j ] , "DONE" ) == 0 ) {
            break;
        }
        /* TIME */
        fgets ( SONG_TIME[ i ] , MAXIMUM_COMPONENTS , stdin );
        if ( SONG_TIME[ i ][ strlen ( SONG_TIME[ i ] ) - 1 ] == '\n' ) {
            SONG_TIME[ i ][ strlen ( SONG_TIME[ i ] ) - 1 ] = '\0';
        }

        while ( strcmp ( SONG_TIME[ i ] , "" ) != 0 ) {
            strcpy( STORED_RESULTS[ i ] , ARTIST[ j ] );
            strcat( STORED_RESULTS[ i ] , "*" );
            strcat( STORED_RESULTS[ i ] , SONG_TIME[ i ] );
            //COUNT OF SONG
            number_of_songs ++;
            i ++;
            fgets ( SONG_TIME[ i ] , MAXIMUM_COMPONENTS , stdin );
            if ( SONG_TIME[ i ][ strlen ( SONG_TIME[ i ] ) - 1 ] == '\n' ) {
                SONG_TIME[ i ][ strlen ( SONG_TIME[ i ] ) - 1 ] = '\0';
            }
        }
        j ++;
    }
}
/* Reading songs from file */
/* REFERENCE FROM read-from-file.c FROM NOTES prompting for a file and reading from it.
  Written by John */
void READ_SONGS_FROM_FILE ( FILE * input_fp , char (* STORED_RESULTS)[300] ) {
    number_of_songs = 0;
    j = 0;
    i = 0;
    /* Till the end of the file */
    while ( ! feof ( input_fp ))
    {
        /*Reading artist data */
        fgets ( ARTIST[ j ] , MAXIMUM_COMPONENTS , input_fp );
        /*  Get rid of the trailing newline, if there is one...  */
        if ( ARTIST[ j ][ strlen ( ARTIST[ j ] ) - 1 ] == '\n' )
        {
            ARTIST[ j ][ strlen ( ARTIST[ j ] ) - 1 ] = '\0';
        }
        fgets ( SONG_TIME[ i ] , MAXIMUM_COMPONENTS , input_fp );
        /* Reading time data */
        if ( SONG_TIME[ i ][ strlen ( SONG_TIME[ i ] ) - 1 ] == '\n')
        {
            SONG_TIME[ i ][ strlen ( SONG_TIME[ i ] ) - 1 ] = '\0';
        }
        /*  Now read from the file, one character at a time.  */
        while ( ! feof ( input_fp ) &&
                ( strcmp ( SONG_TIME[ i ] , "" ) != 0 )) {
            //* APPENDING AND COPYING */
            strcpy( STORED_RESULTS[ i ] , ARTIST[ j ] );
            strcat( STORED_RESULTS[ i ] , "*" );
            strcat( STORED_RESULTS[ i ] , SONG_TIME[ i ] );
            number_of_songs ++; /* SONG COUNT */
            i ++;
            /* TIME OF SONGS FROM USER */
            fgets ( SONG_TIME[ i ] , MAXIMUM_COMPONENTS , input_fp );
            if ( SONG_TIME[ i ][ strlen ( SONG_TIME[ i ] ) - 1 ] == '\n' ) {
                SONG_TIME[ i ][ strlen ( SONG_TIME[ i ] ) - 1 ] = '\0';
            }
        }
        j ++;
    }
}
/* !!!Taking the reference from PRACTICAL 4 (QUESTION 4)[p4q4.c] !!!! */
/* INSERTION SORT*/
void SORT_RESULTS ( char (* STORED_RESULTS)[300] ) {
    i = 0;
    j = 0;
    /* storing elements for swapping*/
    char value[MAXIMUM_LINES][MAXIMUM_COMPONENTS];
    for (i = 1 ; i < number_of_songs ; i ++)
    {
        /* Start i = 1, the first one is sorted.*/
        j = i;
        strcpy( value[ i ] , STORED_RESULTS[ i ] );
        while ( j > 0 && strcmp ( value[ i ] , STORED_RESULTS[ j - 1 ] ) < 0 ) {
            /*  Shuffling items bigger than val by one...  */
            strcpy( STORED_RESULTS[ j ] , STORED_RESULTS[ j - 1 ] );
            j --;
        }
        /*Putting items at right positions */
        strcpy( STORED_RESULTS[ j ] , value[ i ] );
    }
}
/* !!!Taking the reference from PRACTICAL 4 (QUESTION 4)[p4q4.c] !!!! */
/*
This function prints out SORTED results in the array inputResults
and the prints them out according to the given format.
*/
void PRINT_SORT_RESULTS ( char (* STORED_RESULTS)[300] ) {
    i = 0;
    char * token;
    const char delim[] = "*";
    //Copying the songs from results to temporary array//
    for ( i = 0 ; i < number_of_songs ; i ++)
    {
        strcpy( temperory[ i ] , STORED_RESULTS[ i ] );
    }
    /*    FOR REMOVING *    */
    for (i = 0 ; i < number_of_songs ; i ++)
    {
        token = strtok ( temperory[ i ] , delim );
        strcpy( PRESENT_ARTIST[ i ] , token ); //token extraction

        token = strtok (NULL , delim );
        strcpy( SONGS[ i ] , token ); //token extraction

        token = strtok (NULL , delim );
        strcpy( TIME_OF_SONGS[ i ] , token ); //token extraction

        if ( strcmp ( PRESENT_ARTIST[ i ] , PRECEDING_ARTIST[ j ] ) != 0 )
        {
            strcpy( PRECEDING_ARTIST[ j ] , PRESENT_ARTIST[ i ] );
            printf ( "\n%s\n" , PRESENT_ARTIST[ i ] );
        }
        /* Printing them according to giving output */
        printf ( "  --%s***%s  \n" , SONGS[ i ] , TIME_OF_SONGS[ i ] );
    }
}

/*for (i = 0; i < n; i++)
{
j ← random integer such that 0 ≤ j ≤ i
if j!= i
arr[i] ← arr[j]
arr[j] ← source[i]
 TAKING REFERENCE FROM PRACTICAL SHEET 6 (Taken Reference from this)
} */
void RANDOM_RESULTS ( char (* STORED_RESULTS)[300] ) {
    i = 0;
    for ( size_t i = 0 ; i < number_of_songs ; i ++ )
    {
        //COPYING THE STORED RESULTS INTO RANDOM ARRAY */
        strcpy( RANDOM_ARRAY[ i ] ,STORED_RESULTS[ i ] );
    }

    for ( size_t i = 1 ; i < number_of_songs ; i ++ ) {
        j = rand ( ) % i; /*RANDOM GENERATOR FUNCTION */
        if ( j != i ) /*when j and i ar not the same*/
                                               {
                                                       strcpy( RANDOM_ARRAY[ i ] , RANDOM_ARRAY[ j ] );
                                               }
        //COPYING THE RANDOM ARRAY */
        strcpy( RANDOM_ARRAY[ j ] , STORED_RESULTS[ i ] );
    }
}

/* TAKEN REFERENCE FROM LECTURE 9 (GENERATE PLAYLIST FUNCTION)*/
/* LECTURE 9 [GENERATE PLAYLIST FUNCTION] */
void PRINT_RANDOM_RESULTS ( char (* STORED_RESULTS)[300] )
{
    ENTIRE_PLAYLIST_TIME = 0;
    counting = 0;
    printf ( "The Randomised Playlist will be as follows::\n" );
    for ( size_t i = 0 ; i < number_of_songs ; i ++ )
    {
        /*copying arrays*/
                 strcpy( temperory[ i ] , RANDOM_ARRAY[ i ] );
    }
    while ( i < number_of_songs && ENTIRE_PLAYLIST_TIME < MAXIMUM_TIME ) {
        /* UPDATING PREVIOUS ARTIST AND PREVPREV ARTIST */
        strcpy( ARTISTE[ i ] , PRECEDING_ARTIST[ i ] );
        strcpy( PRECEDING_ARTIST[ i ] , PRESENT_ARTIST[ i ] );
/* TRYING TO GET CURRENT ARTIST */
        const char delim[] = "*";
        token = strtok ( temperory[ i ] , delim );
        strcpy( PRESENT_ARTIST[ i ] , token );

        if ( ! ( ( strcmp ( PRESENT_ARTIST[ i ] , PRECEDING_ARTIST[ i ] ) == 0 ) &&
                 ( strcmp ( PRESENT_ARTIST[ i ] , ARTISTE[ i ] ) == 0 ) ) ) {
            counting  = 0;
            for ( size_t j = 0 ; j < i ; j ++ ) {
                if ( ( strcmp ( PRESENT_ARTIST[ i ] , PRESENT_ARTIST[ j ] ) ==
                       0 ) ) { counting  ++; } //count is incremented
            }
            /* GETTING SONG TITLE AND DURATION */
            if ( counting  < 3 ) {
                token = strtok ( NULL , delim );
                strcpy( SONGS[ i ] , token ); //token extracted
                token = strtok ( NULL , delim );
                strcpy( TIME_OF_SONGS[ i ] , token ); //token extracted
                const char div[] = ":";
                token = strtok ( TIME_OF_SONGS[ i ] , div );
                // FUNCTION TO CONVERT THE LENGTH OF SONGS FROM CHAR TO INT
                int minutes = atoi ( token );
                token = strtok ( NULL , div );
                int seconds = atoi ( token );
                /*EXTRACTING SONG DURATION IN SECONDS*/
                                             ENTIRE_PLAYLIST_TIME += ( ( 60 * minutes ) + seconds );
                /*PRINTING PRESENT ARTIST,SONG AND SONG DURATION */
                printf ( "--%s: %s (%d:%02d)--\n" , PRESENT_ARTIST[ i ] , SONGS[ i ] , minutes ,
                         seconds );
            }
        }
        i ++;
    }
    /*CONVERTING THE TIME */
    minitue = ENTIRE_PLAYLIST_TIME / 60;
    seconds = ENTIRE_PLAYLIST_TIME % 60;
    printf ( "Total duration: <%d:%02d>" , minitue , seconds );
}