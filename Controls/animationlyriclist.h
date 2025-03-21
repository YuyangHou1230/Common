#ifndef ANIMATIONLYRICLIST_H
#define ANIMATIONLYRICLIST_H

#include <QWidget>
#include <QLabel>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>

class QPropertyAnimation;
class AnimationLyricList : public QWidget
{
    Q_OBJECT
public:
    explicit AnimationLyricList(QWidget *parent = nullptr);

    void loadList(QStringList list);

    void animationToLine(int index);

    void recalculate(QSize size);

protected:
    void resizeEvent(QResizeEvent *event) override;

    struct LyricItem
    {
        QLabel*label;
        QPropertyAnimation *animation;

        LyricItem()
        {

        }

        LyricItem(QLabel *_label, QPropertyAnimation *_animatiom)
        {
            label = _label;
            animation = _animatiom;
        }
    };

private:
    QStringList m_list;
    QList<LyricItem*> m_items;
    QParallelAnimationGroup *m_animationGrop;
    int m_index = 0;

};

#endif // ANIMATIONLYRICLIST_H
