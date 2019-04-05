 #include <unistd.h>
   #include <fcntl.h>
   #include <sys/stat.h>
   #include <sys/mman.h>
   #include <stdio.h>
   #include <string.h>
   #include <iostream>

   using namespace std;

   int main( int argc, char *argv[] ) {
      if( argc != 2 ) {
         cerr << "Usage: " << argv[0] << " file" << endl;
         return -1;
      }

     // open the file READ-ONLY
      int fd_in = open( argv[1], O_RDONLY );
      if( fd_in < 0 ) {
         perror( argv[1] );                           // check if an error occurred
         return -1;
      }
      struct stat info;
      if( fstat( fd_in, &info ) < 0 ) {
         perror( "Error stating input file\n" );
         return -1;
      }

     // map the input file into memory
      char *addr_in = (char *)mmap( 0, info.st_size, PROT_READ, MAP_SHARED, fd_in, 0 );
      if( addr_in == MAP_FAILED ) {
         perror( "Error mapping input file\n" );
         return -1;
      }


     for (int i = 0; i < info.st_size; i++) {
	if (addr_in[i] == 'X'){
		printf("Success: X has been found.\n");
		return 0;
	}
     }
	
      printf("Failed: No X found.\n");
      return 0;
   }
