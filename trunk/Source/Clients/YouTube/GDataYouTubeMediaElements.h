/* Copyright (c) 2008 Google Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

//
//  GDataYouTubeMediaElements.h
//


#undef _EXTERN
#undef _INITIALIZE_AS
#ifdef GYOUTUBMEDIAEELEMENTS_DEFINE_GLOBALS
#define _EXTERN 
#define _INITIALIZE_AS(x) =x
#else
#define _EXTERN extern
#define _INITIALIZE_AS(x)
#endif

_EXTERN int kGDataYouTubeMediaContentFormatRTSPStream _INITIALIZE_AS(1);
_EXTERN int kGDataYouTubeMediaContentFormatHTTPURL _INITIALIZE_AS(5);
_EXTERN int kGDataYouTubeMediaContentFormatMobileRTSPStream _INITIALIZE_AS(6);

#import "GDataObject.h"
#import "GDataMediaContent.h"
#import "GDataMediaRating.h"
#import "GDataMediaGroup.h"
#import "GDataMediaCredit.h"
#import "GDataYouTubeElements.h"

// media content with YouTube's addition of an integer format attribute, 
// like yt:format="1"
@interface GDataMediaContent (YouTubeExtensions)
- (NSNumber *)youTubeFormatNumber;
- (void)setYouTubeFormatNumber:(NSNumber *)num;
@end

// media rating with YouTube's addition of a country attribute, 
// like yt:country="USA"
@interface GDataMediaRating (YouTubeExtensions)
- (NSString *)youTubeCountry;
- (void)setYouTubeCountry:(NSString *)str;
@end

// media credit with YouTube's addition of a type attribute,
// like yt:type="partner" (v2.0)
@interface GDataMediaCredit (YouTubeExtensions)
- (NSString *)youTubeCreditType;
- (void)setYouTubeCreditType:(NSString *)str;
@end


// a media group that uses the YouTube media content elements instead
// of the generic media content elements
@interface GDataYouTubeMediaGroup : GDataMediaGroup
- (NSNumber *)duration; // int, in seconds
- (void)setDuration:(NSNumber *)num;

- (BOOL)isPrivate;
- (void)setIsPrivate:(BOOL)flag;

// videoID available in v2.0
- (NSString *)videoID;
- (void)setVideoID:(NSString *)str;

// uploadedDate available in v2.0
- (GDataDateTime *)uploadedDate;
- (void)setUploadedDate:(GDataDateTime *)dateTime;
@end