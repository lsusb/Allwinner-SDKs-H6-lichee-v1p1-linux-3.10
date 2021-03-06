/*
 * Copyright (C) 2016
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef SUNXI_BUDGET_INTERFACE_H
#define SUNXI_BUDGET_INTERFACE_H

int sunxi_cpufreq_update_state(struct sunxi_budget_cooling_device *cooling_device, u32 cluster);
struct sunxi_budget_cpufreq *
sunxi_cpufreq_cooling_register(struct sunxi_budget_cooling_device *bcd);
void sunxi_cpufreq_cooling_unregister(struct sunxi_budget_cooling_device *bcd);
int sunxi_cpufreq_get_roomage(struct sunxi_budget_cooling_device *cooling_device,
					u32 *freq_floor, u32 *freq_roof, u32 cluster);
int sunxi_cpufreq_set_roomage(struct sunxi_budget_cooling_device *cooling_device,
					u32 freq_floor, u32 freq_roof, u32 cluster);

#ifdef CONFIG_BUDGET_HOTPLUG_CPU
extern int sunxi_hotplug_update_state(struct sunxi_budget_cooling_device *cooling_device, u32 cluster);
extern struct sunxi_budget_hotplug *
sunxi_hotplug_cooling_register(struct sunxi_budget_cooling_device *bcd);
extern void sunxi_hotplug_cooling_unregister(struct sunxi_budget_cooling_device *bcd);
int sunxi_hotplug_get_roomage(struct sunxi_budget_cooling_device *cooling_device,
				u32 *num_floor, u32 *num_roof, u32 cluster);
int sunxi_hotplug_set_roomage(struct sunxi_budget_cooling_device *cooling_device,
				u32 num_floor, u32 num_roof, u32 cluster);
#else
static inline int sunxi_hotplug_update_state(struct sunxi_budget_cooling_device *cooling_device, u32 cluster){return 0;}
static inline struct sunxi_budget_hotplug *
sunxi_hotplug_cooling_register(struct sunxi_budget_cooling_device *bcd){return NULL;}
static inline void sunxi_hotplug_cooling_unregister(struct sunxi_budget_cooling_device *bcd){}
int sunxi_hotplug_get_roomage(struct sunxi_budget_cooling_device *cooling_device,
				u32 *num_floor, u32 *num_roof, u32 cluster){return 0;}
int sunxi_hotplug_set_roomage(struct sunxi_budget_cooling_device *cooling_device,
				u32 num_floor, u32 num_roof, u32 cluster){return 0;}
#endif /* CONFIG_HOTPLUG_CPU */

#endif
