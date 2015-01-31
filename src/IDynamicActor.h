#ifndef __IDYNAMICACTOR_H_
#define __IDYNAMICACTOR_H_


class IDynamicActor
{
    public:
        virtual ~IDynamicActor() {}
        virtual void Idle() = 0;
        virtual void MoveLeft() = 0;
        virtual void MoveRight() = 0;
        virtual void MoveUp() = 0;
        virtual void MoveDown() = 0;
        virtual void DropBomb() = 0;
};

#endif //__IDYNAMICACTOR_H_
