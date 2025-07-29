#ifndef _IHTTPRESPONSE_H_
#define _IHTTPRESPONSE_H_

class IHttpResponse {
public:
  virtual void Ok() = 0;
  virtual void NotAllowed() = 0;
  virtual void NotFound() = 0;
};

#endif
