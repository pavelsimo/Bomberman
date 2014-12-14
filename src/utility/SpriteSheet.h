#ifndef __SPRITE_H_
#define __SPRITE_H_

#include <map>
#include "Texture.h"
#include "SpriteSheetXMLParser.hxx"

struct Sprite
{
    uint32_t x;
    uint32_t y;
    uint32_t w;
    uint32_t h;
};

typedef std::map<std::string, Sprite> SpriteMap;

class SpriteSheet : public Texture
{
    public:
        SpriteSheet();
        ~SpriteSheet();

        void AddSprite(const std::string& name, uint32_t x, uint32_t y, uint32_t w, uint32_t h);
        Sprite GetSprite(const std::string &name);
        bool LoadSpritesFromXML(const std::string &filename);

    private:
        SpriteMap m_sprites;
};

#endif //__SPRITE_H_
