/*

   ＡＥＳＴＨＥＴＩＣ.c
   Copyright (C) 2017 Eggplant Systems and Design, LLC
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
   OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// UNICODE CODEPOINT TO UTF-8 BYTE STREAM
void fput_utf8cp(uint32_t nCPoint, FILE *pFile) {

   if( nCPoint <= 0x7f ) {

      fprintf(pFile, "%c", (char) nCPoint & 0x7f);
   }
   else if( nCPoint <= 0x7ff ) {

      fprintf(pFile, "%c%c", (char) (0xc0 | (nCPoint >> 6)),
                         (char) (0x80 | (nCPoint & 0x3f))
      );
   }
   else if( nCPoint <= 0xffff ) {

      fprintf(pFile, "%c%c%c", (char) (0xe0 | (nCPoint >> 12)),
                           (char) (0x80 | ((nCPoint >> 6) & 0x3f)),
                           (char) (0x80 | (nCPoint & 0x3f))
      );
   }
   else if( nCPoint <= 0x1fffff ) {

      fprintf(pFile, "%c%c%c%c", (char) (0xf0 | (nCPoint >> 18)),
                             (char) (0x80 | ((nCPoint >> 12) & 0x3f)),
                             (char) (0x80 | ((nCPoint >> 6) & 0x3f)),
                             (char) (0x80 | (nCPoint & 0x3f))
      );
   }
}

int main (int argc, char *argv[]) {

   const size_t IO_BUF_SIZE = (32 * 1024);

   FILE*    pFile = NULL;
   int      chr, nFlag;
   int      bFlagsPassed = 0;

   char buffIn[IO_BUF_SIZE];
   char buffOut[IO_BUF_SIZE];

   memset(buffIn,  '\0', sizeof(buffIn));
   memset(buffOut, '\0', sizeof(buffOut));

   // PARSE OPTIONS
   while( 1 ) {

      nFlag = getopt(argc, argv, "hf:");

      if( nFlag == -1 ) {

         break;
      }
      else if( (nFlag == 'h') && !bFlagsPassed ) {

         printf(
"\nＡＥＳＴＨＥＴＩＣ VERSION 0.1 BETA\n"
"   Makes your words more ＡＥＳＴＨＥＴＩＣ, sends result to STDOUT.\n\n"
"USAGE:\n"
"   ＡＥＳＴＨＥＴＩＣ [OPTION]...\n\n"
"OPTIONS:\n"
"   -f      INPUT FILENAME (uses STDIN if omitted)\n"
"   -h      HELP: THIS MESSAGE\n\n"
"NOTES:\n"
"   Runs in ＩＮＴＥＲＡＣＴＩＶＥ　ＭＯＤＥ when STDIN is the TTY.\n"
"   Press Ctrl+D to send an EOF character to exit.\n\n"
         );

         return 0;
      }
      else if( nFlag == 'f' ) {

         pFile = fopen(optarg, "r");

         if( pFile == NULL ) {

            fprintf(stderr, "FAILED TO OPEN INPUT: '%s' - %s\n", optarg, strerror(errno));
            return 1;
         }

         bFlagsPassed = 1;
      }
   }

   if( pFile == NULL )
      pFile = stdin;

   // DEFAULT TO FULL BUFFERING (FILES & PIPES)
   int nBufferMode = _IOFBF;
   int bIsTTY      = isatty(fileno(pFile));

   // LINE BUFFER MODE FOR TERMINAL
   if( bIsTTY )
      nBufferMode = _IOLBF;

   // IO BUFFERING
   setvbuf(stdout, buffOut, nBufferMode, sizeof(buffOut));
   setvbuf(pFile,  buffIn , nBufferMode, sizeof(buffIn));

   if( bIsTTY )
      printf("ＩＮＴＥＲＡＣＴＩＶＥ　ＭＯＤＥ (PRESS CTRL+D TO EXIT):\n");

   // TRANSLATE TO TITLE CAPS
   while( 1 ) {

      chr = fgetc(pFile);

      if( chr == EOF )
         break;

      // ASCII CHARS
      if( (chr >= 0x21) && (chr <= 0x7E) ) {

         fput_utf8cp((chr - 0x21) + 0xff01, stdout);
      }
      // SPACE
      else if (chr == ' ') {

         fput_utf8cp(0x3000, stdout);
      }
      // OTHER
      else {

         fputc(chr, stdout);
      }
   };

   fflush(stdout);

   if( pFile != stdin )
      fclose(pFile);

   return 0;
}