#include "Chunk_Layer.h"

#include <iostream>

#include "Chunk.h"
#include "../Block/D_Blocks.h"
#include "../World_Constants.h"

Chunk_Layer::Chunk_Layer()
{
    for (auto x = 0 ; x < World::CHUNK_SIZE ; x++)
    {
        for (auto z = 0 ; z < World::CHUNK_SIZE ; z++)
        {
            m_blocks[World::CHUNK_SIZE * z + x] = Block_Pointer();
        }
    }
}

void Chunk_Layer::setBlock(int x, int z, const Block::Block_Data& block)
{
    m_blocks[World::CHUNK_SIZE * z + x] = {block.getID()};
}

const Block::Block_Data& Chunk_Layer::getBlock(int x, int z) const
{
    return Block::get((Block::ID)(m_blocks[World::CHUNK_SIZE * z + x].id));
}
