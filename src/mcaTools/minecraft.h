/*
 * minecraft.h
 *
 *  Created on: Feb 10, 2023
 *      Author: danducky
 */

#ifndef SRC_MCATOOLS_MINECRAFT_H_
#define SRC_MCATOOLS_MINECRAFT_H_

typedef struct chunk_location
{
	unsigned char	offset[3];
	unsigned char	sector_count;
} ChunkLocation;

typedef struct chunk_timestamp
{
	unsigned int timestamp;
} ChunkTimestamp;

#define CHUNKS_PER_REGION 1024

typedef struct region_file_header
{
	ChunkLocation locations[CHUNKS_PER_REGION];
	ChunkTimestamp timestamps[CHUNKS_PER_REGION];
} RegionFileHeader;

typedef struct chunk_data_header
{
	unsigned char	length[4];
	unsigned char	compression_type;
} ChunkDataHeader;

#define COMPRESSION_TYPE_GZIP 1
#define COMPRESSION_TYPE_ZLIB 2

#endif /* SRC_MCATOOLS_MINECRAFT_H_ */
