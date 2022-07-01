#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//modifies the volume of a wav audio file

struct header
{
	    // RIFF Chunk
    uint8_t         Chunk_ID[4];        // RIFF
    uint32_t        Chunk_data_Size;      // RIFF Chunk data Size
    uint8_t         RIFF_TYPE_ID[4];        // WAVE
    // format sub-chunk
    uint8_t         Chunk1_ID[4];         // fmt
    uint32_t        chunk1_data_Size;  // Size of the format chunk
    uint16_t        Format_Tag;    //  format_Tag 1=PCM
    uint16_t        Num_Channels;      //  1=Mono 2=Sterio
    uint32_t        Sample_rate;  // Sampling Frequency in (44100)Hz
    uint32_t        byte_rate;    // Byte rate
    uint16_t        block_Align;     // 4
    uint16_t        bits_Per_Sample;  // 16
    /* "data" sub-chunk */
    uint8_t         chunk2_ID[4]; // data
    uint32_t        chunk2_data_Size;  // Size of the audio data
} FULLHEADER;

int main(int argc, char *arcv[])
{
	if(argc != 4)
	{
		printf("Usage: waw.c input output filter\n");
		return 1;
	}
	FILE *input = fopen(arcv[1], "rb");
	
	if(!input) return 1;
	
	FILE *output = fopen(arcv[2], "wb");
	
	if(!output) return 1; 
	
	float filter = atof(arcv[3]);
	//write the header to output file
	fread(&FULLHEADER, 1, sizeof(FULLHEADER), input);
	fwrite(&FULLHEADER, 1, sizeof(FULLHEADER), output);
	
	uint16_t buffer;	
	while(fread(&buffer, sizeof(buffer), 1, input))
	{
		buffer *= filter;
		fwrite(&buffer, sizeof(buffer), 1, output);
	};

	fclose(input);
	fclose(output);
	return 0;
}
