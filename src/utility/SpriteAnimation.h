#ifndef __SPRITEANIMATION_H_
#define __SPRITEANIMATION_H_

#include "SpriteSheet.h"
#include "Vector2.h"
#include "Drawing.h"

typedef std::vector<std::string> FrameList;

class SpriteAnimation
{
    public:
        // ctor & dtor
        //
        SpriteAnimation();
        ~SpriteAnimation();

        std::size_t Size() const;

        // Frames
        //
        void AddFrame(const std::string& spriteName);

        // Sprite sheet
        //
        const SpriteSheet* GetSpriteSheet() const;
        void SetSpriteSheet(SpriteSheet* spriteSheet);

        // Position
        //
        Vector2 GetPosition() const;
        void SetPosition(const Vector2& pos);
        void SetPosition(float x, float y);

        // Iterators
        //
        bool NextFrame();
        bool PrevFrame();

        // Render
        //
        void Render();

    private:
        uint32_t m_curFrame;
        FrameList m_frames;
        Vector2 m_position;
        SpriteSheet* m_spriteSheet;
};

#endif //__SPRITEANIMATION_H_

