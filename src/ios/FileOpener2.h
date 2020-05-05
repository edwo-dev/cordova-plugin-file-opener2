/*
The MIT License (MIT)

Copyright (c) 2013 pwlin - pwlin05@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#import <Cordova/CDV.h>

// *****************************************************************************
// CUSTOM: 2020-05-05
// Custom preview controller.
// *****************************************************************************

@import QuickLook;

@interface CustomPreviewController : QLPreviewController
- (void)hideShareButton;
@end

@interface PreviewItem : NSObject <QLPreviewItem>
  @property(readonly, nullable, nonatomic) NSURL    *previewItemURL;
  @property(readonly, nullable, nonatomic) NSString *previewItemTitle;
@end

@interface PDFDataSource : NSObject <QLPreviewControllerDataSource>
  @property (strong, nonatomic) PreviewItem *item;
@end

@interface FileOpener2 : CDVPlugin <UIDocumentInteractionControllerDelegate, QLPreviewControllerDelegate> {
    NSString *localFile;
    NSString* callbackId;
}

@property(nonatomic, strong) UIDocumentInteractionController *controller;
@property(nonatomic, strong) CDVViewController *cdvViewController;
@property(strong, nonatomic) PDFDataSource *pdfDatasource;

- (void) open: (CDVInvokedUrlCommand*)command;

@end

/*
@interface FileOpener2 : CDVPlugin <UIDocumentInteractionControllerDelegate> {
    NSString *localFile;
}

@property(nonatomic, strong) UIDocumentInteractionController *controller;
@property(nonatomic, strong) CDVViewController *cdvViewController;

- (void) open: (CDVInvokedUrlCommand*)command;

@end
*/
