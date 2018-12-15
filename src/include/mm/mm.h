#ifndef INCLUDE_MM_MM_H_
#define INCLUDE_MM_MM_H_



#include <include/mm/pmm.h>
#include <include/mm/vmm.h>
#include <include/mm/slob.h>

// 内存管理子系统初始化
void mm_init(void);

// 为指定进程分配一个页框
uint32_t alloc_page(pid_t pid);
// 释放指定页框
void free_page(uint32_t p);

/**
 * 初始化分页表
 * PAGE_TABLE_BASE_ADDR 中存放的是页表的基地址
 * PAGE_SIZE 为页面大小
 * 采用单级页表
 * 虚拟地址中高20位为虚拟页号，低12位为偏移量
 * 物理地址中高12位为物理页号，低12位为偏移量
 **/
void page_init1(int* begin, int* end){
    /**
     * begin 为物理内存起始地址
     * end 为物理内存结束地址
     */ 

}

/**
 * TLB 中未找到对应的物理页引发的异常
 * 可以通过寄存器获得引发异常的虚拟页号，然后通过查询页表，返回物理页号即可
 **/
void page_fault1(int vpn){

}

#endif // INCLUDE_MM_MM_H_