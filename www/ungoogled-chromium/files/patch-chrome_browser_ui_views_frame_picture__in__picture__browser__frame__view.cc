--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc.orig	2023-03-10 11:01:21 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc
@@ -40,7 +40,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/frame/browser_frame_view_paint_utils_linux.h"
 #include "chrome/browser/ui/views/frame/desktop_browser_frame_aura_linux.h"
 #endif
@@ -61,7 +61,7 @@ constexpr int kBackToTabImageSize = 16;
 // The height of the controls bar at the top of the window.
 constexpr int kTopControlsHeight = 30;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Frame border when window shadow is not drawn.
 constexpr int kFrameBorderThickness = 4;
 #endif
@@ -151,7 +151,7 @@ class WindowEventObserver : public ui::EventObserver {
 
     gfx::Rect input_bounds = pip_browser_frame_view_->GetLocalBounds();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Calculate input bounds for Linux. This is needed because the input bounds
     // is not necessary the same as the local bounds on Linux.
     if (pip_browser_frame_view_->ShouldDrawFrameShadow()) {
@@ -341,7 +341,7 @@ PictureInPictureBrowserFrameView::PictureInPictureBrow
   hide_close_button_animation_.set_continuous(false);
   hide_close_button_animation_.set_delegate(this);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   frame_background_ = std::make_unique<views::FrameBackground>();
 #endif
 
@@ -460,7 +460,7 @@ void PictureInPictureBrowserFrameView::OnThemeChanged(
   for (ContentSettingImageView* view : content_setting_views_)
     view->SetIconColor(color_provider->GetColor(kColorPipWindowForeground));
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // On Linux the top bar background will be drawn in OnPaint().
   top_bar_container_view_->SetBackground(views::CreateSolidBackground(
       color_provider->GetColor(kColorPipWindowTopBarBackground)));
@@ -505,7 +505,7 @@ void PictureInPictureBrowserFrameView::RemovedFromWidg
   BrowserNonClientFrameView::RemovedFromWidget();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 gfx::Insets PictureInPictureBrowserFrameView::MirroredFrameBorderInsets()
     const {
   auto border = FrameBorderInsets();
@@ -710,7 +710,7 @@ void PictureInPictureBrowserFrameView::AnimationProgre
 // views::View implementations:
 
 void PictureInPictureBrowserFrameView::OnPaint(gfx::Canvas* canvas) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Draw the PiP window frame borders and shadows, including the top bar
   // background.
   if (window_frame_provider_) {
@@ -833,7 +833,7 @@ void PictureInPictureBrowserFrameView::UpdateTopBarVie
 }
 
 gfx::Insets PictureInPictureBrowserFrameView::FrameBorderInsets() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (window_frame_provider_) {
     const auto insets = window_frame_provider_->GetFrameThicknessDip();
     const auto tiled_edges = frame()->tiled_edges();
@@ -854,7 +854,7 @@ gfx::Insets PictureInPictureBrowserFrameView::FrameBor
 }
 
 gfx::Insets PictureInPictureBrowserFrameView::ResizeBorderInsets() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameBorderInsets();
 #else
   return gfx::Insets(kResizeBorder);
@@ -865,7 +865,7 @@ int PictureInPictureBrowserFrameView::GetTopAreaHeight
   return FrameBorderInsets().top() + kTopControlsHeight;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PictureInPictureBrowserFrameView::SetWindowFrameProvider(
     ui::WindowFrameProvider* window_frame_provider) {
   DCHECK(window_frame_provider);
