/* Copyright (C) 
 * 2011 - Xu Wenzhang(xwz), carl.xwz@gmail.com, http://xuwenzhang.org
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */
/**
 * @file mydebug.h
 * @brief 自己的调试信息库，可以通过ENABLE_DEBUG来设置开关
 * @author Xu Wenzhang(xwz), carl.xwz@gmail.com, http://xuwenzhang.org
 * @version 1.0
 * @date 2011-06-08
 */
#ifndef _MYDEBUG_H_
#define _MYDEBUG_H_
//调试信息开关
#ifdef ENABLE_DEBUG

#include <stdio.h>
//打印文件名和行号
#define FLOUT printf("\33[1;31m%s:%d \33[0m", __FILE__, __LINE__);

//打印函数名和自定义打印信息
#define Debug(...) printf("\33[1;32m%s()\33[0m: ", __func__);\
					printf(__VA_ARGS__);\
					printf("\n")

//打印文件名，行号，函数名和自定义调试信息
#define VDebug(...)	FLOUT\
					Debug(__VA_ARGS__)
#ifdef __cplusplus
#include <typeinfo>

//打印类名，函数名和自定义调试信息
#define CDebug(...)	printf("\33[1;34m%s\33[0m::", typeid(*this).name());\
					Debug(__VA_ARGS__);

//打印文件名，行号，类名，函数名和自定义调试信息
#define VCDebug(...) FLOUT\
					CDebug(__VA_ARGS__)
#endif

#else
#define Debug(...)
#define VDebug(...)
#define CDebug(...)
#define VCDebug(...)

#endif


#endif /* end of include guard: _MYDEBUG_H_ */
