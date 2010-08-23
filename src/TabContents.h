#import <Cocoa/Cocoa.h>

class TabStripModel; // Note: C++ class

@interface TabContents : NSObject {
  BOOL isApp_;
  BOOL isLoading_;
  id delegate_;
  unsigned int closedByUserGesture_; // TabStripModel::CloseTypes
	NSView *view_; // the actual content
}

@property(assign, nonatomic) BOOL isApp;
@property(assign, nonatomic) BOOL isLoading;
@property(assign, nonatomic) id delegate;
@property(assign, nonatomic) unsigned int closedByUserGesture;
@property(assign, nonatomic) NSView *view;

-(void)closingOfTabDidStart:(TabStripModel*)closeInitiatedByTabStripModel;

@end

@protocol TabContentsDelegate
-(BOOL)canReloadContents:(TabContents*)contents;
-(BOOL)reload; // should set contents->isLoading_ = YES
@end

