/*
 * Copyright © 2011 Christian Persch
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TERMINAL_CLIENT_UTILS_H
#define TERMINAL_CLIENT_UTILS_H

#include <gio/gio.h>
#include <gio/gunixfdlist.h>

G_BEGIN_DECLS

void terminal_client_append_create_instance_options (GVariantBuilder *builder,
                                                     const char      *display_name,
                                                     const char      *startup_id,
                                                     const char      *geometry,
                                                     const char      *role,
                                                     const char      *profile,
                                                     const char      *encoding,
                                                     const char      *title,
                                                     gboolean         active,
                                                     gboolean         maximise_window,
                                                     gboolean         fullscreen_window);

typedef struct {
  int index;
  int fd;
} PassFdElement;

void terminal_client_append_exec_options            (GVariantBuilder *builder,
                                                     gboolean         pass_environment,
                                                     const char      *working_directory,
                                                     PassFdElement   *fd_array,
                                                     gsize            fd_array_len,
                                                     gboolean         shell);

char * terminal_client_get_fallback_startup_id      (void) G_GNUC_MALLOC;

char const* const* terminal_client_get_environment_filters (void);

char** terminal_client_filter_environment           (char** envv) G_GNUC_MALLOC;

GSettings* terminal_g_settings_new (GSettingsSchemaSource* source,
                                    char const* schema_id);

GSettings* terminal_g_settings_new_with_path (GSettingsSchemaSource* source,
                                              char const* schema_id,
                                              char const* path);

G_END_DECLS

#endif /* TERMINAL_UTIL_UTILS_H */
