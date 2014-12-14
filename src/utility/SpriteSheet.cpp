#include "SpriteSheet.h"

SpriteSheet::SpriteSheet()
: Texture()
{

}

SpriteSheet::~SpriteSheet()
{
    m_sprites.clear();
}

void SpriteSheet::AddSprite(const std::string &name, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{
    Sprite sprite;
    sprite.x = x;
    sprite.y = y;
    sprite.w = w;
    sprite.h = h;

    SpriteMap::iterator lb = m_sprites.lower_bound(name);

    // Efficient add or update (Effective STL - Item 24)
    if(lb != m_sprites.end() && !(m_sprites.key_comp()(name, lb->first)))
    {
        lb->second = sprite;
    }
    else
    {
        m_sprites.insert(lb, SpriteMap::value_type(name, sprite));
    }
}


Sprite SpriteSheet::GetSprite(const std::string &name)
{
    if(!m_sprites.empty())
    {
        std::map<std::string , Sprite>::iterator it;
        it = m_sprites.find(name);
        if(it != m_sprites.end())
        {
            return it->second;
        }
    }

    Sprite sprite;
    sprite.x = 0;
    sprite.y = 0;
    sprite.w = 0;
    sprite.h = 0;

    return sprite;
}

bool SpriteSheet::LoadSpritesFromXML(const std::string &filename)
{
    try
    {
        std::auto_ptr<TextureAtlas> textureAtlas (TextureAtlas_(filename,
                xml_schema::flags::dont_validate));

        std::string texAtlasImgPath = static_cast<std::string>(textureAtlas->imagePath());
        int texAtlasWidth = textureAtlas->width();
        int textAtlasHeight = textureAtlas->height();

        TextureAtlas::sprite_sequence& ss(textureAtlas->sprite());

        for (auto spriteIt = ss.begin(); spriteIt != ss.end(); ++spriteIt)
        {
            std::string name = static_cast<std::string>(spriteIt->n());
            int x = spriteIt->x();
            int y = spriteIt->y();
            int w = spriteIt->w();
            int h = spriteIt->h();
            AddSprite(name, x, y, w, h);
        }
    }
    catch (const xml_schema::exception& e)
    {
        std::cerr << e << std::endl;
        return false;
    }
    return true;
}