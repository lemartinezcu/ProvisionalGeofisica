/***************************************************************************
**
**  Copyright (C) 2002-2009 Marc Wathelet. All rights reserved.
**
**  This file is part of geopsypackinstall.
**
**  This file may be distributed and/or modified under the terms of the
**  GNU General Public License version 2 or 3 as published by the Free
**  Software Foundation and appearing in the file LICENSE.GPL included
**  in the packaging of this file.
**
**  This file is distributed in the hope that it will be useful, but WITHOUT
**  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
**  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
**  more details.
**
**  See http://www.geopsy.org for more information.
**
**  Created : 2009-02-26
**
***************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <windows.h>
//#include <cstdlib>

int main( int argc, char ** argv )
{
  /*
    Arguments:
    - first one must be "key342134" to prevent abusive calls
    - A letter: 'f' or 'd', for file or directory
    - The full path to the file or directory to remove
    - As many file or directory specifications needed
  */
  if( argc<2 || strcmp(argv[1],"key342134")!=0 ) {
    //fprintf(stderr, "Geopsy.org residual uninstaller\n");
    return 2;
  }
  Sleep(1000); // sleep during 1 seconds
  // Make 10 tries and then give up
  int error=2;
  int itry, iarg;
  for(itry = 0; itry<10; itry++) {
    error=0;
    for(iarg=2; iarg<argc; iarg+=2) {
      if (iarg+1>=argc) {
        //fprintf(stderr, "Wrong argument number %i\n",argc);
        return 2;
      }
      struct stat sInfo;
      if(stat(argv[iarg+1], &sInfo)==0) {
        if (argv[iarg][0]=='f') {
          //fprintf(stderr, "Remove file %s\n",argv[iarg+1]);
          if (remove(argv[iarg+1])!=0) error=2;
        } else {
          //fprintf(stderr, "Remove directory %s\n",argv[iarg+1]);
          if (rmdir(argv[iarg+1])!=0) error=2;
	}
      }
    }
    if(error==0) break;
    Sleep(5000); // sleep during 5 seconds
  }
  return error;
}
