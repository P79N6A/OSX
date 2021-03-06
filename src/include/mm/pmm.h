/*
 * 物理内存管理
 * 主要为初始化空闲空间链表
 */

#ifndef INCLUDE_MM_PMM_H_
#define INCLUDE_MM_PMM_H_

// 支持的最大物理内存
#define PMM_MAX_SIZE 0x0003FFFC

// 内核在物理内存中的起始位置
// TODO: 修改内核大小
#define RAM_KERNEL_START 0x80000000

// 内核在物理内存中的结束位置
// 需要 4KB 对齐
// TODO: 修改内核大小
#define RAM_KERNEL_STOP 0x8003FFFC

// 物理内存的起始与结束位置
#define RAM_START 0x80000000
#define RAM_STOP 0x8003FFFC

// 页面大小 4K
#define PMM_PAGE_SIZE 0x1000
// 页掩码 4K 对齐地址
#define PAGE_MASK  0xfffff000

// 页表起始位置（页目录位置）
#define PTE_ADDR ((RAM_KERNEL_STOP & 0xfffff000) + 0x1000)

// 最多支持的物理页面个数
#define PAGE_MAX_COUNT ((RAM_STOP - PTE_ADDR) / PMM_PAGE_SIZE - 1)

#include <types.h>
#include <atomic.h>

// 物理内存管理初始化
void pmm_init();

uint32_t pmm_alloc_page();

void pmm_free_page(uint32_t p);

// 当前可用内存页
uint32_t free_pages_count(void);

// 物理页结构
// typedef struct page_t {
//         atomic_t ref;                // 物理页被引用的次数
//         uint32_t flag;               // 当前页状态
//         uint32_t ncount;             // 当前页后续连续页的数量  First-Fit算法需要
//         struct list_head list;       // 链接下一个连续页
// } page_t;

// page_t 的 flag 参数的操作宏
// #define PG_RESERVED     (0)       // 1 << 0 表示页当前不可用
// #define PG_NCOUNT       (1)       // 1 << 1 表示 ncount 字段有效
// #define PG_ORDER        (2)       // 1 << 2 表示 order 字段有效

// #define set_page_reserved_flag(page)       set_bit(PG_RESERVED, &((page)->flag))
// #define clear_page_reserved_flag(page)     clear_bit(PG_RESERVED, &((page)->flag))
// #define is_page_reserved(page)             test_bit(PG_RESERVED, &((page)->flag))

// #define set_page_ncount_flag(page)          set_bit(PG_NCOUNT, &((page)->flag))
// #define clear_page_ncount_flag(page)        clear_bit(PG_NCOUNT, &((page)->flag))
// #define is_page_ncount(page)                test_bit(PG_NCOUNT, &((page)->flag))

// #define set_page_order_flag(page)          set_bit(PG_ORDER, &((page)->flag))
// #define clear_page_order_flag(page)        clear_bit(PG_ORDER, &((page)->flag))
// #define is_page_order(page)                test_bit(PG_ORDER, &((page)->flag))

// static inline int32_t page_ref(page_t *page)
// {
//         return atomic_read(&page->ref);
// }

// static inline void set_page_ref(page_t *page, int32_t val)
// {
//         atomic_set(&page->ref, val);
// }

// static inline void page_ref_inc(page_t *page)
// {
//         atomic_inc(&page->ref);
// }

// static inline void page_ref_dec(page_t *page)
// {
//         atomic_dec(&page->ref);
// }

// 由物理地址计算出该地址所处页的管理结构的指针
// page_t *addr_to_page(uint32_t addr);

// 由页的管理结构的指针计算出页所在物理地址
// uint32_t page_to_addr(page_t *page);

// // 物理内存页面管理的栈
// extern uint32_t pmm_stack[];
// // 物理内存管理的栈指针
// extern uint32_t pmm_stack_top;
// // 物理内存页的数量
// extern uint32_t phy_page_count;

// 内存管理子系统管理对象
// struct pmm_manager {
//         const char *name;                                // 管理算法的名称
//         void (*page_init)(page_t *pages, uint32_t n);    // 初始化
//         uint32_t (*alloc_pages)(uint32_t n);             // 申请物理内存页(n为字节数)
//         void (*free_pages)(uint32_t addr, uint32_t n);   // 释放内存页
//         uint32_t (*free_pages_count)(void);              // 返回当前可用内存页
// };

// 物理内存管理初始化
// void pmm_init(void);

// 内存管理算法初始化
// void page_init(page_t *pages, uint32_t n);

// 申请内存页
// uint32_t alloc_pages(uint32_t n);

// 释放内存页
// void free_pages(uint32_t addr, uint32_t n);

// #define alloc_page alloc_pages(1)
// #define free_page(addr) free_pages(addr, 1)

// 当前可用内存页
// uint32_t free_pages_count(void);

#endif  // INCLUDE_MM_PMM_H_
