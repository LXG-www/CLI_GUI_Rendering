/***
 * @Date         : 2020-04-14 21:41:50
 * @Author       : MemoryShadow
 * @LastEditors  : MemoryShadow
 * @LastEditTime : 2020-08-27 07:59:55
 * @Description  : 一个看着小球弹跳的测试游戏
 */

#include "CLI_GUI_Rendering.h"

int main(int argc, char const *argv[])
{
    clear_screen(); // 清除屏幕
    // 在最开始创建主绘制层(窗口层)
    Window_layer *main_layer = new_Window_layer(20, 15);
    //边界图层
    struct Paint_layer *edge_layer = new_Paint_layer(main_layer);

    // 绘制周围边界
    for (unsigned index = 1; index < main_layer->width - 1; index++)
    {
        Write_Point(edge_layer, index, 0, '-');
        Write_Point(edge_layer, index, main_layer->height - 1, '-');
    }
    for (unsigned index = 1; index < main_layer->height - 1; index++)
    {
        Write_Point(edge_layer, 0, index, '|');
        Write_Point(edge_layer, main_layer->width - 1, index, '|');
    }
    // 小球层
    struct Paint_layer *ball_layer = new_Paint_layer(main_layer);
    // 小球运动代码
    {
        unsigned width = 1, height = 1;
        int width_flag = 1, height_flag = 1;
        // 绘制
        Write_Point(ball_layer, width += width_flag, height += height_flag, '*');
        while (1)
        {
            // 撞墙判断
            if ((width >= (ball_layer->width - 2)) || (width <= 1))
            {
                printf("W:%d H:%d WF:%d HF:%d\t\n", width, height, width_flag, height_flag);
                width_flag = -width_flag;
            }
            if ((height >= (ball_layer->height - 2)) || (height <= 1))
            {
                printf("W:%d H:%d WF:%d HF:%d\t\n", width, height, width_flag, height_flag);
                height_flag = -height_flag;
            }
            // system("cls");
            WindowDraw(main_layer, 1);
            // 移动并计算位置
            layer_Move(ball_layer, (width_flag < 0 ? Left : Right) | (height_flag < 0 ? Up : Down), 1);
            width += width_flag;
            height += height_flag;
        }
    }
    delete_Window_layer(main_layer);
    return 0;
}
