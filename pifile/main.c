/*  

 piFile
 
 pifiles.io
 
 Everything that is and ever will be in in π.
 
 Idea and implementation based from the amazing project from philipl
 πfs https://github.com/philipl/pifs
 
 I wanted a way to play without having to mess around with OXSFUSE or
 similar and can forsee that (with some optimisation/experimentation
 and processing power!) that file compression will never be the same
 again!
 
 Copyright (C) 2013  Will Townsend | @vfxguynz
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 */

#include <stdio.h>
#include <limits.h>
#include <string.h>

unsigned char get_byte(int id);

int main(int argc, const char * argv[])
{
    
    printf("piFile\n");
    
    if ( argc < 3 ) /* argc should be 2 for correct execution */
    {
        printf("Invalid args, please read the readme and try again.");
    }
    else
    {
        
        if (strcmp(argv[1], "-g") == 0) {
            
            // -- Generate file from .pifile
            
            printf("Generating file from .piFile\n");
            
            FILE *sourceFile = fopen( argv[2], "r" );
            
            FILE *destinationFile = fopen( argv[3], "wb+" );
            
            if (sourceFile == 0 || destinationFile == 0) {
                
                printf("There was an error opening files, please try agin, fool!");
                
            } else {
                
                short index = 10;
                
                while (fread(&index, sizeof(short), 1, sourceFile) == 1)
                {
                    char c = (char) get_byte(index);
                    fwrite(&c, sizeof(char), 1, destinationFile);
                }
                
                fclose(sourceFile);
                fclose(destinationFile);
                                
            }
            
        } else {
            
            // -- Generate Meta Data File from normal file
            
            printf("Generating .piFile\n");
            
            FILE *sourceFile = fopen( argv[1], "r" );
            
            FILE *destinationFile = fopen( argv[2], "wb+" );
            
            if (sourceFile == 0 || destinationFile == 0) {
                
                printf("There was an error opening files, please try agin, fool!");
                
            } else {
                
                short c;
                int i = 0;
                
                while ((c = fgetc(sourceFile)) != EOF)
                {
                    short index;
                    
                    for (index = 0; index < SHRT_MAX; index++) {
                        
                        if (get_byte(index) == c) {
                            printf("Part %d - [pi %d]\t%d \n", i, index, c);
                            break;
                        }
                    }
                    
                    fwrite(&index, sizeof(index), 1, destinationFile);
                    
                    i++;
                }
                
                fclose(sourceFile);
                fclose(destinationFile);
                
            }
        }
    }
    
    printf("Completed. Have fun now.");
    
    return 0;
}

